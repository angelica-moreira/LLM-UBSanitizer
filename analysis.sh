#!/bin/bash

# Function to get the current timestamp
timestamp() {
  date +"%Y-%m-%d %H:%M:%S"
}

# Function to compile the file and generate LLVM IR
compile_and_gen_llvm_ir() {
  local file="$1"
  local compiler="$2"
  local output_dir="$3"
  
  base=$(basename "$file")
  no_ext="${base%.*}"
  
  echo "$(timestamp) Using $compiler to compile file: $base."

  $compiler "$file" -S -emit-llvm -c -Xclang -disable-O0-optnone -Wall -Wextra -Wpedantic -std=c11 -o "${output_dir}/${no_ext}.ll" 2>> "${output_dir}/${no_ext}_clang.log"

  res=$?

  if [[ $res != 0 ]]; then
    echo "$(timestamp) FAIL: LLVM IR generation for $base."
  else
    echo "$(timestamp) SUCCESS: LLVM IR generation for $base."
  fi
}

# Function to run Frama-C analysis
run_frama_c_analysis() {
  local file="$1"
  local function_name="$2"
  local output_dir="$3"
  
  base=$(basename "$file")
  no_ext="${base%.*}"

  echo "$(timestamp) Running Frama-C analysis on function: ${function_name}"

  frama-c -eva -main "${function_name}" "$file" &> "${output_dir}/${no_ext}_frama_report.log"

  res=$?

  if [[ $res != 0 ]]; then
    echo "$(timestamp) FAIL: Frama-C analysis for $base."
  else
    echo "$(timestamp) SUCCESS: Frama-C analysis for $base."
  fi
}

# Check if the input file exists
if [[ ! -f "$1" ]]; then
  echo "$(timestamp) ERROR: File $1 does not exist."
  exit 1
fi

# Variables
f="$1"
base=$(basename "$f")
no_ext="${base%.*}"
ext="${base##*.}"  # Get the file extension
size=$(stat -c%s "$f")
dir=$(dirname "$f")

function_name=${f#*_c_}
function_name=${function_name%.c}

# Determine the appropriate compiler based on the file extension
if [[ "$ext" == "c" ]]; then
  cc="clang"
elif [[ "$ext" == "cpp" || "$ext" == "cc" || "$ext" == "cxx" ]]; then
  cc="clang++"
else
  echo "$(timestamp) ERROR: Unsupported file extension: $ext"
  exit 1
fi

echo "$(timestamp) File: $base. Number of bytes: $size"

# Compile the file to LLVM IR
compile_and_gen_llvm_ir "$f" "$cc" "$dir"

# Run Frama-C analysis if the file
run_frama_c_analysis "$f" "$function_name" "$dir"

# Starting the npx command in the background and save the PID
npx --yes genaiscript@1.49.1 serve &
PID=$!

# Waiting for a few seconds to ensure the server starts up properly
sleep 10

# Perform other tasks here
echo "GenAI Server is running with PID $PID"

# Run UBSanitizer with genaiscript
echo "$(timestamp) Running UBSanitizer with genaiscript on $f"
npx genaiscript run $(pwd)/genaisrc/UBSsanitizer.genai.mjs "$f" --no-cache


sleep 5
# Check if a file with the same name and extension but with the postfix '_fixed' exists
fixed_file="${dir}/${no_ext}_fixed.${ext}"

if [[ -f "$fixed_file" ]]; then
  echo "$(timestamp) SUCCESS: Fixed file found: $fixed_file"
  
  clang-format -i $fixed_file

  # Compile the fixed file to LLVM IR
  compile_and_gen_llvm_ir "$fixed_file" "$cc" "$dir"
  
  # Run Frama-C analysis on the fixed file
  run_frama_c_analysis "$fixed_file" "$function_name" "$dir"
else
  echo "$(timestamp) INFO: No fixed file found for $base."
fi

PID=$(lsof -t -i:8003)
if [ -n "$PID" ]; then
  kill -9 $PID
  echo "Killed process $PID using port 8003"
fi

kill $PID
echo "GenAI Server with PID $PID has been terminated"
