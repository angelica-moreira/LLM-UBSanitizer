import os
import json
import subprocess
import tempfile
import shutil
import re
import logging
from dotenv import load_dotenv, find_dotenv
from openai import AzureOpenAI, OpenAI
from azure.identity import AzureCliCredential, get_bearer_token_provider

# Load environment variables from .env file
env_file = find_dotenv(".env")
load_dotenv(env_file)

# Set up logging configuration to capture INFO and WARNING messages
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)

# Initialize Azure OpenAI client
def initialize_openai_client():
    try:
        azure_endpoint = os.getenv("AZURE_ENDPOINT")
        api_version = os.getenv("API_VERSION")
        scope = os.getenv("SCOPE")
        model_name = os.environ["MODEL_NAME"]
        
        if not azure_endpoint or not api_version or not scope or not model_name:
            logging.error("Missing required environment variables: AZURE_ENDPOINT, API_VERSION, SCOPE or MODEL.")
            return None
        
        # Get Azure AD token using Azure CLI credentials
        credential = AzureCliCredential()
        access_token = credential.get_token(scope)
        
        client = AzureOpenAI(
            azure_endpoint=azure_endpoint,
            api_version=api_version,
            azure_ad_token_provider=lambda: access_token.token
        )
        logging.info("Azure OpenAI client initialized successfully.")
        return client, model_name
    except Exception as e:
        logging.error(f"Error initializing Azure OpenAI client: {e}", exc_info=True)
        return None

def initialize_github_openai_client():
    try:
        # Environment variable validation
        token = os.environ["GITHUB_TOKEN"]
        endpoint = os.environ["GITHUB_ENDPOINT"]
        model_name = os.environ["MODEL_NAME"]

        if not token or not endpoint or not model_name:
            logging.error("Missing required environment variables: GITHUB_TOKEN, GITHUB_ENDPOINT, or MODEL_NAME.")
            return None
      
        client = OpenAI(
            base_url=endpoint,
            api_key=token,
        ) 

        logging.info("GitHub OpenAI client initialized successfully.")
        return client, model_name

    except Exception as e:
        logging.error(f"Error initializing Azure GitHub client: {e}", exc_info=True)
        return None

# Function to get a response from the Azure OpenAI client
def get_bot_response(client, messages, model, temperature=0):
    """Retrieve a response from the language model."""
    if not client:
        logging.error("Azure OpenAI client is not initialized.")
        return None
    
    try:
        response = client.chat.completions.create(
            model=model,
            messages=messages,
            max_tokens=1000,
            temperature=temperature,
            top_p=1,
            frequency_penalty=0,
            presence_penalty=0,
        )
        return response.choices[0].message.content
    except Exception as e:
        logging.error(f"Error retrieving response from model: {e}")
        return None

def terminate_process(process):
    # Get the list of all running processes
    processes = subprocess.check_output(['ps', 'aux']).decode('utf-8')
    
    # Check for MIRI processes
    for line in processes.splitlines():
        if process in line:
            # Extract the PID
            pid = int(line.split()[1])
            os.kill(pid, 9)  # Force kill the process

def emit_llvm_ir(source_file, output_file):
    """Generate LLVM-IR using rustc from the provided Rust source file."""
    # Ensure the source file exists and is an absolute path
    if not os.path.isabs(source_file):
        logging.error("The source file path must be absolute.")
        return
    
    if not os.path.exists(source_file):
        logging.error(f"The source file does not exist: {source_file}")
        return

    # Set the current working directory to the directory of the source file
    working_dir = os.path.dirname(source_file)
    
    try:
        subprocess.run(
            [
                "rustc",
                # Ensure same crate name to avoid the difference in the mangled names.
                "--crate-name=llvm_export",
                "--emit=llvm-ir",
                source_file,
                "-o",
                output_file
            ],
            check=True,
            cwd=working_dir  # Set the working directory
        )
        logging.info(f"LLVM-IR has been saved to {output_file}")
    except subprocess.CalledProcessError as e:
        logging.error(f"Failed to generate LLVM-IR for {source_file}: {e}")

def create_cargo_project(temp_dir):
    """Set up a new Cargo project in a temporary directory."""
    cargo_dir = os.path.join(temp_dir, "temp_project")
    os.makedirs(os.path.join(cargo_dir, "src"))

    # Create a basic Cargo.toml file
    with open(os.path.join(cargo_dir, "Cargo.toml"), 'w') as f:
        f.write("[package]\nname = \"temp_project\"\nversion = \"0.1.0\"\nedition = \"2021\"\n")

    return cargo_dir

def copy_source_to_project(source_file, cargo_dir):
    """Copy the source code file into the project's source directory, preserving the original."""
    shutil.copy(source_file, os.path.join(cargo_dir, "src", "main.rs"))

def run_command(command):
    """Execute a shell command and log the output."""
    with open('stdout.log', 'a') as stdout_file, open('stderr.log', 'a') as stderr_file:
        logging.info(f"Running command: {command}")
        process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

        for stdout_line in iter(process.stdout.readline, ""):
            logging.info("STD OUT LINE")
            logging.info(stdout_line.strip())
            stdout_file.write(stdout_line)
        process.stdout.close()

        _, stderr_output = process.communicate()
        if stderr_output:
            logging.error(stderr_output)
            stderr_file.write(stderr_output)

    return process.returncode, process

def run_miri_on_code(cargo_dir, base_file_name):
    """Run MIRI on the created Cargo project."""
    process = None
    try:
        process = subprocess.Popen(
            ["cargo", "+nightly", "miri", "run"],
            cwd=cargo_dir,  # Set the working directory
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        
        # Wait for the process to complete
        stdout, stderr = process.communicate()
        log_file = f"{base_file_name}_miri_output.log"
        stderr_log_file = f"{base_file_name}_stderr.log"
        # Write the logs to files
        with open(log_file, "w") as stdout_log:
            stdout_log.write(stdout)
        with open(stderr_log_file, "w") as stderr_log:
            stderr_log.write(stderr)

        if process.returncode != 0:
            logging.info(
                "MIRI found error(s) in the code, check {} and {} for more details.".format(
                    log_file, stderr_log_file
                )
            )
    except Exception as e:
        logging.error(f"Error running MIRI: {e}")
        if process is not None:
            process.terminate()
        exit(1)
    return process, stderr_log_file

def run_miri(source_file, base_file_name):
    """Creates a temporary cargo project, runs MIRI, and manages logs."""
    temp_dir = tempfile.mkdtemp()
    miri_output = "" 

    try:
        cargo_dir = create_cargo_project(temp_dir)
        copy_source_to_project(source_file, cargo_dir)
        os.chdir(cargo_dir)
        process, stderr_log_file = run_miri_on_code(cargo_dir, base_file_name)

        # Read the contents of the stderr log file into miri_output
        with open(stderr_log_file, 'r') as log_file:
            miri_output = log_file.read()

        return miri_output

    except Exception as e:
        logging.error(f"An error occurred while running MIRI: {e}", exc_info=True)
        exit(1)
    finally:
        os.chdir("..")
        shutil.rmtree(temp_dir)
        process.terminate()

def save_json_report(report_data, report_file_path):
    """Save the JSON report to the file system."""
    try:
        with open(report_file_path, 'w') as report_file:
            json.dump(report_data, report_file, indent=4)
        logging.info(f"JSON report has been saved to {report_file_path}")
    except json.JSONDecodeError as e:
        logging.error(f"Failed to save JSON report: {e}")

def extract_json_report(json_report):
    """Extract JSON report from the bot's response."""
    try:
        pattern = r'```json\s*(.*?)\s*```'  
        match = re.search(pattern, json_report, re.DOTALL) 
        if match:
            json_content = match.group(1).strip() 
            return json.loads(json_content) 
        else:
            logging.error("No valid JSON content found in the response.")
            return None
    except json.JSONDecodeError as e:
        logging.error(f"Failed to extract JSON report: {e}")
        return None

def extract_source_code(text):
    """Extract source code from the text response."""
    pattern = r'```rust\n(.*?)\n```'
    match = re.search(pattern, text, re.DOTALL)
    if match:
        return match.group(1).strip()
    else:
        logging.error("No code block found.")
        return ""

def analyze_code_for_bugs(client, model, file_path):
    """Analyze the Rust code for potential bugs using the LLM."""
    messages = []

    # Initial prompt to set the context
    system_message = (
       "You are a Rust compiler engineer with deep expertise in code analysis. "
       "Analyze the provided Rust source code for potential issues, particularly "
       "focusing on ownership, borrowing, lifetimes, and memory safety. Provide "
       "detailed insights and suggest improvements where necessary, taking into "
       "account Rust's strict safety guarantees and best practices."
    )
    messages.append({"role": "system", "content": system_message})

    # Read the source code from the file
    with open(file_path, 'r') as file:
        source_code = file.read().strip()
        if source_code:
            messages.append({"role": "user", "content": source_code})
            # Request analysis
            analysis_report = get_bot_response(client, messages, model)
            if analysis_report:
                logging.info(f"Bot Analysis Report:\n{analysis_report}")
                messages.append({"role": "assistant", "content": analysis_report})
                return source_code, analysis_report
    return None

def generate_comprarison_json_report(client, model, analysis_report, miri_output):
    """Generate a JSON report comparing LLM analysis with MIRI output."""
    messages = []

    # Combine analysis results
    messages.append({"role": "system", "content": "Summarize the findings of LLM analysis and MIRI output."})
    messages.append({"role": "assistant", "content": analysis_report})
    messages.append({"role": "assistant", "content": miri_output})

    # Request the comparison and summary
    messages.append({
        "role": "user",
        "content": (
            "Please, generate a comprehensive JSON report comparing the bug findings from the LLM analysis and the MIRI output. "
            "For each bug, indicate whether both approaches identified it, or if only one did. Highlight the specific bugs where "
            "the results diverge and provide a summary of which method found the most issues. Also, include a count of the total "
            "bugs detected by each method, along with any key differences in their findings."
        )
    })

    bot_json_report = get_bot_response(client, messages, model)
    if bot_json_report:
        logging.info(f"Bot JSON Report:\n{bot_json_report}")
        return extract_json_report(bot_json_report)
    return None

def request_fix_suggestions(client, model, analysis_report, source_code):
    """
    Requests detailed code fix suggestions from a language model based on a bug report and source code.
    If the bug report includes code suggestions, they are highlighted separately to avoid redundant analysis.
    """

    # Prepare messages for the language model
    messages = [
        {"role": "system", "content": (
            "You are an expert in Rust code analysis. Provide a detailed review based on the bug report and source code."
        )},
        {"role": "user", "content": f"Bug Report (could contain recommendations for fixing the source code):\n{analysis_report}"},
        {"role": "user", "content": f"Rust source code to be analyzed:\n{source_code}"},
        {"role": "user", "content": (
            "If the bug report includes code suggestions, review them for accuracy and completeness. "
            "Return an answer with detailed explanations for each suggested fix, and include a final version "
            "of the fixed code at the end in a markdown block (```rust ... ```)."
        )}
    ]

    # Request fix suggestions from the language model
    bot_fix_suggestions = get_bot_response(client, messages, model)
    if bot_fix_suggestions:
        logging.info(f"Received Fix Suggestions:\n{bot_fix_suggestions}")
        return bot_fix_suggestions

    logging.warning("No fix suggestions were returned by the language model.")
    return None


import os
import re
import logging

def apply_fixes_to_code(client, model, source_code_path, source_code, fix_suggestions):
    """
    Apply the suggested fixes to the source code by rewriting it according to the model's recommendations.
    This step is crucial for improving the code based on the analysis.
    """
    messages = []

    # Include the fix suggestions and the original source code
    messages.append({"role": "system", "content": "Based on the following fix suggestions, apply them to the source code."})
    messages.append({"role": "user", "content": fix_suggestions})
    messages.append({"role": "user", "content": source_code})

    # Request the model to rewrite the code with the applied fixes
    messages.append({
    "role": "user",
    "content": ( "Please apply the suggested fixes to the provided source code and return ONLY the modified code in markdown format, "
                 "without any language identifiers or other information. Ensure it is formatted with triple backticks. "
                 "If the code is sound and does not require fixing, return the text: THE CODE IS SOUND.")})


    bot_fixed_code = get_bot_response(client, messages, model)

    # Check if the response contains the fixed code in markdown format
    if bot_fixed_code:
        # Check for the phrase "THE CODE IS SOUND"
        if "THE CODE IS SOUND" in bot_fixed_code:
            logging.info("The code does not need any fixes.")
            return ""

        # Use regex to extract the code block in markdown format
        match = re.search(r'```(.*?)```', bot_fixed_code, re.DOTALL)
        if not match:
            return None
        else:
            fixed_code = match.group(1).strip()  # Extract the code without the markdown
            # Create a new file path for the fixed code
            fixed_code_path = os.path.splitext(source_code_path)[0] + '_fixed' + os.path.splitext(source_code_path)[1]

            # Save the fixed code to the new file
            with open(fixed_code_path, 'w') as fixed_file:
                fixed_file.write(fixed_code)

            logging.info(f"Fixed code saved to: {fixed_code_path}")
            return fixed_code, fixed_code_path
        
    logging.warning("Something went wrong and the model returned nothing.")
    return None

def run_alive_tv(src_file, tgt_file, log_file):
    """Run Alive-TV to check the semantics of the source and target LLVM-IR files and log the output."""
    # Ensure the source and target files exist and are absolute paths
    if not os.path.isabs(src_file) or not os.path.isabs(tgt_file):
        logging.error("Both source and target file paths must be absolute.")
        return
    
    if not os.path.exists(src_file):
        logging.error(f"The source file does not exist: {src_file}")
        return
    
    if not os.path.exists(tgt_file):
        logging.error(f"The target file does not exist: {tgt_file}")
        return

    # Set the current working directory to the directory of the source file
    working_dir = os.path.dirname(src_file)
    
    # Open the log file to write the output
    with open(log_file, 'w') as output_file:
        try:
            # Run Alive-TV, using 'tee' to redirect both to the screen and to the log file
            subprocess.run(
                [
                    "bash", "-c", f"alive-tv {src_file} {tgt_file} | tee {log_file}"
                ],
                check=True,
                cwd=working_dir  # Set the working directory
            )
            logging.info(f"Alive-TV check completed for {src_file} and {tgt_file}. Output logged to {log_file}.")
        except subprocess.CalledProcessError as e:
            logging.error(f"Failed to run Alive-TV for {src_file} and {tgt_file}: {e}")

def generate_json_report(client, model, analysis_report, fix_suggestions, fixed_code):
    """
    Generate a detailed JSON report that summarizes the analysis,
    suggestions for fixes, and the fixed code. This report can be useful for tracking changes.
    """
    messages = []

    # Combine all the relevant information
    messages.append({"role": "system", "content": "Based on the previous analysis, suggestions, and fixed code:"})
    messages.append({"role": "assistant", "content": analysis_report})
    messages.append({"role": "assistant", "content": fix_suggestions})
    messages.append({"role": "assistant", "content": fixed_code})

    # Ask the model to create a JSON report
    messages.append({
        "role": "user",
        "content": (
            "Please generate a detailed JSON report based on the analysis, suggestions, and fixed code. "
            "Include file name, line number, error description, code snippets before and after the fix, "
            "and explanations for each fix."
        )
    })

    bot_json_report = get_bot_response(client, messages, model)
    if bot_json_report:
        logging.info(f"Bot JSON Report:\n{bot_json_report}")
        return extract_json_report(bot_json_report)
    return None


def analyze_and_fix_code(file_path, endpoint="1"):
    """Main function to analyze and fix the Rust code."""
    if not os.path.exists(file_path):
        logging.error(f"File {file_path} does not exist.")
        return None

    openai_client = None
    model = None
    if endpoint == "1":
        openai_client, model = initialize_github_openai_client()
    elif endpoint == "2":
        openai_client, model = initialize_openai_client()
    else:
        logging.error(f"Endpoint connection option {endpoint} does not exist.")
        return None
        
    # Step 1: Analyze the code for bugs using the LLM
    source_code, analysis_report = analyze_code_for_bugs(openai_client, model, file_path)
    if not source_code:
        logging.error("Source code is empty. Please provide the Rust source code for analysis.")
        return None
    if not analysis_report:
        logging.warning("The analysis report did not yield any results. This may indicate a problem during the analysis phase. Please verify the inputs and analysis procedures.")
        return None

    # Step 2: Request suggestions and apply the fixes
    # Get fix suggestions
    fix_suggestions = request_fix_suggestions(openai_client, model, analysis_report, source_code)

    if not fix_suggestions:
        logging.error("It looks like the code fix suggestions are empty. There may have been an issue, or perhaps the code is sound as it stands. Please review the steps to identify any possible issues.")
        return None
    
    # Apply the suggested fixes to the original code
    result = apply_fixes_to_code(openai_client, model, file_path, source_code, fix_suggestions)
    if result is None or result == "":
        return None
    
    fixed_code, fixed_code_path = result

    # Step 3: Generate LLM report file
    # Generate a JSON report for the analysis and fixes
    json_report = generate_json_report(openai_client, model, analysis_report, fix_suggestions, fixed_code)

    # Get the base name of the source code file without its extension
    base_file_name = os.path.splitext(file_path)[0]

    # Create the report file name with the suffix "_llmreport.json"
    report_file_name = f"{base_file_name}_llmreport.json"

    # Save the JSON report to a file in the benchmark folder
    save_json_report(json_report, os.path.join(os.path.dirname(file_path), report_file_name))

    # Step 4: Run MIRI to analyze the code
    miri_output = run_miri(file_path, base_file_name)
    if not miri_output:
        logging.error("No MIRI report generated.")
        return None
    terminate_process("miri")

    # Step 5: Generate a comparison JSON report
    json_report = generate_comprarison_json_report(openai_client, model, analysis_report, miri_output)
    if json_report:
        report_file_path = f"{base_file_name}_report.json"
        save_json_report(json_report, report_file_path)

    # Step 6: Emit LLVM-IR from the original source code
    original_ir_file = f"{base_file_name}.ll"
    emit_llvm_ir(file_path, original_ir_file)

    # Step 7: Emit LLVM-IR from the fixed source code
    fixed_ir_file = f"{base_file_name}_fixed.ll"
    emit_llvm_ir(fixed_code_path, fixed_ir_file)

    # Step 8: Check if the fixed code preserves the semantics of the original code
    alive2_log_file = f"{base_file_name}_alive2.log"
    run_alive_tv(original_ir_file, fixed_ir_file, alive2_log_file)

if __name__ == "__main__":
    file_path = os.path.abspath(input("Enter the path to the Rust source code file: "))
    logging.info(f"Absolute Rust source code path: {file_path}")
    analyze_and_fix_code(file_path)
