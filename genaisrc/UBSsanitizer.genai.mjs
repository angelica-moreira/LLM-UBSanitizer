// metadata (including model parameters)
// learn more at https://aka.ms/genaiscript
// model: "openai:gpt-3.5-turbo"
script({
    title: "UBSanitizer",
    description: "Check if C code has bugs that could lead to undefined behavior.",
    model: "openai:gpt-3.5-turbo",
    system: ["system"],
    files: ["benchmarks/linux/sound/core/"],
  });
  
  const schema = defSchema("DATA", {
    type: "array",
    items: {
      type: "object",
      properties: {
        file_name: { type: "string" }, // file name
        line: { type: "number" }, // line number of the error
        code: { type: "string" }, // snippet of the code with the error
        error: { type: "string" }, //description of the error
        fix: { type: "string" }, // detailed description of the fix
        code_fix: { type: "string" }, // snippet of the code with the fix
      },
      required: ["file_name", "line", "error", "code", "fix", "code_fix"],
    },
  });
    
  const file = def(
    "CFILE",
    env.files.filter((f) => {
      return (
        f.filename && (f.filename.endsWith(".c") || f.filename.endsWith(".cpp"))
      );
    }),
    { lineNumbers: true }
  );

  defTool(
    "Save_To_File",
    "Persists the input data to a file in the file system. This tool is deterministic, \
      always return the same output for the same input.",
    {
      type: "object",
      properties: {
        inputData: {
          type: "object",
          description: "The data that will be persisted in the file system.",
          properties: {
            filename: {
              type: "string",
              description: "The file name with extension.",
            },
            directory:{
              type: "string",
              description: "The directory path to save the file",
            },
            content: {
              type: "string",
              description: "The file's content.",
            },
          },
          required: ["filename", "directory", "content"],
        },
      },
      required: ["inputData"],
    },
  
    async (params) => {
      const { inputData } = params;
      const dir = await path.resolve(inputData.directory);
      const file = `${dir}/${inputData.filename}`;
      try {
        // Attempt to write to the file
        await workspace.writeText(file, inputData.content);
        // If successful, return or log a success message
        console.log("File written successfully");
        return "Success";
      } catch (error) {
        // If an error occurs, log or handle the error
        console.error("Error writing file:", error);
        return "Error";
      } 
    }
  );


  $`You are an expert in C/CPP programming! Execute the following tasks: \
  # Check for bugs that could lead to undefined behavior in the ${file}. If you find any, provide detailed explanations and recommendations for addressing the issue. \
  Be extremely careful when doing the analysis and suggesting the fix, make sure to provide a detailed explanation of the bug and how to fix it. \
  Add line numbers to the code snippet. \
  Follow the template below to report the bugs: \
  # Detailed Bug Analysis and Reporting for ${file} \

  ## 1. Use-After-Free Detection \
  - **Task1:** Check for any use-after-free bugs in ${file}. If detected: \
    - Highlight the specific location in the code. \
    - Include line numbers. \
    - Provide a detailed explanation of the bug and how to fix it. \

  ## 2. Reporting
  - **Task2:** Parse the output of the previous task and create a comprehensive report summarizing all the identified bugs. Follow the instructions below: \
          Instructions: \
            1) Provide detailed explanations and solutions for each issue, \
            including why the code is problematic, how to fix it, and why the \
            proposed solution is optimal.\
            2) Print in the console the following information: \
              - File name \
              - Line number \
              - Detailed Error description \
              - Code snippet with the error \
              - Detailed Fix description \
              - Code snippet with the fix applied to it. \
            3) Use the JSON ${schema} provided above to structure the output. \
            4) Make sure to include all the bugs found in the report. \
            5) Save the JSON object for further analysis. \
            Use the "Save_To_File" tool to save the \
             report, passing the ${file} name withou extension, appending the postfix '_UBSanitizer_Report.json', also ${file} \
             full path directly, along with the JSON object as \
             parameters.
            6) Override the generated JSON report file if needed. \

   ## 3. Apply Fixes
   - **Task3:** Apply the fixes to the code in ${file}. \
      Instructions: \
       1) Based on the analysis from the previous task, apply the recommended fixes for each reported bug in ${file}. \
       2) Use the "Save_To_File" tool to save the updated file, passing the ${file} name without extension, appending the postfix '_fixed' and ${file} extension, also ${file} \
             full path directly, along with the updated code as parameters. \
       3) Override the fixed source file if needed. \
  # End of Bug Analysis for ${file}.


  `;
