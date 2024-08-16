#!/bin/bash
cc="clang"

timestamp() {
	date +"%Y-%m-%d__%H:%M:%S"
}

default_path="$(pwd)/linux"

bench_path=${1:-$default_path}
bench_path=$(readlink -f $1)
if [ ! -d "$bench_path" ]; then
    echo "Error: Directory '$bench_path' does not exist."
    echo "Usage: $0 <source_dir>"
    echo "source_dir -> folder containing programs to be compiled."
    exit 1
fi

echo "Using benchmark directory: $bench_path"

echo "$(timestamp) ----- BEGINNING COMPILATION -----"

files=$(find $bench_path -name "*.c")

for f in $files; do
	base=$(basename $f)
	no_ext=${base%.*}
	size=$(stat -c%s "${f}")
	dir=$(dirname "$f")

	function_name=${f#*.c_}
        function_name=${function_name%.c}

	echo "$(timestamp) Attempting to compile file: $base. Number of bytes: $size"

	$cc $f -S -emit-llvm -c -Xclang -disable-O0-optnone -Wall -Wextra -Wpedantic -std=c11 -o "${dir}/${no_ext}.ll" 2>> "${dir}/${no_ext}_clang.log"
	
	res=$?

	if [[ $res != 0 ]]
	then
		echo "${base},${size},FAIL LLVM IR" | tee "${dir}/${no_ext}_llvm_ir.log"
	else
		echo "${base},${size},SUCCESS LLVM IR" | tee "${dir}/${no_ext}_llvm_ir.log" 
	fi

	echo ${function_name}
	frama-c -eva -main ${function_name} ${f} &> "${dir}/${no_ext}_frama_report.log"

	res=$?

	if [[ $res != 0 ]]
	then
		echo "${base},${size},FAIL FRAMA" | tee "${dir}/${no_ext}_frama_eva.log"
	else
		echo "${base},${size},SUCCESS FRAMA" | tee "${dir}/${no_ext}_frama_eva.log" 
	fi
done

echo "$(timestamp) ----- FINISHED COMPILATION -----"
