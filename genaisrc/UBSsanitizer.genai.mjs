// metadata (including model parameters)
// learn more at https://aka.ms/genaiscript
// model: "openai:gpt-3.5-turbo"
script({
    title: "UBSanitizer",
    description: "Check if C code has bugs that could lead to undefined behavior.",
    model: "ollama:llama3.1",
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
  
  $`You are an expert in C/CPP programming! Execute the following tasks: \
  # Check for bugs that could lead to undefined behavior in the ${file}. If you find any, provide detailed explanations and recommendations for addressing the issue. \
  Be extremely careful when doing the analysis and suggesting the fix, make sure to provide a detailed explanation of the bug and how to fix it. \
  Add line numbers to the code snippet. \
  Follow the template below to report the bugs: \
  # Detailed Bug Analysis and Reporting for ${file} \

  ## 1. Undefined Behavior Analysis \
  - **Task1:** Check if ${file} contains any undefined behavior bugs. Be thorough in your analysis and provide detailed explanations. \

  ## 2. Use-After-Free Detection \
  - **Task2:** Check for any use-after-free bugs in ${file}. If detected: \
    - Highlight the specific location in the code. \
    - Include line numbers. \
    - Provide a detailed explanation of the bug and how to fix it. \

  ## 3. Memory Management Issues \
  - **Task3:** Identify any memory leaks in ${file}. Provide detailed explanations and recommendations for addressing the leaks. \
  - **Task4:** Look for buffer overflow bugs. Document their locations in the code with line numbers. Explain the bug and suggest fixes. \
  - **Task5:** Check for buffer underflow issues. Highlight and explain any instances found, including line numbers and potential fixes. \
  - **Task6:** Detect any null pointer dereference bugs. Provide detailed information on where and how these bugs occur, and suggest corrections. \
  - **Task7:** Identify memory corruption bugs. Document their locations and explain how to resolve them. \

  ## 4. Memory Allocation and Deallocation Issues \
  - **Task8:** Examine ${file} for memory allocation issues. Include details on any problems found and their resolutions. \
  - **Task9:** Check for memory deallocation bugs. Highlight any issues and provide explanations and fixes. \
  - **Task10:** Investigate any memory access problems. Document these issues with line numbers and detailed explanations. \

  ## 5. Additional Memory-Related Bugs \
  - **Task11:** Analyze memory initialization for any issues. Provide line numbers and detailed explanations if problems are found. \
  - **Task12:** Look for memory reallocation bugs. Document and explain any issues detected. \
  - **Task13:** Identify any problems related to memory copy operations. Include line numbers and suggested fixes. \
  - **Task14:** Check for issues with memory move operations. Document findings and provide detailed explanations. \
  - **Task15:** Examine memory comparison bugs. Highlight any issues and suggest fixes. \

  ## 6. Other Memory-Related Concerns \
  - **Task16:** Check for any additional types of memory bugs not covered in the previous tasks. Document and explain any issues found. \
  - **Task17:** Look for any other bugs that could potentially lead to undefined behavior. Provide detailed explanations and suggested fixes. \

  ## 7. Reporting
  - **Task18:** Create a comprehensive report summarizing all the bugs identified in ${file}. Include:
    - Detailed descriptions.
    - Code snippets with line numbers.
    - Suggested fixes for each bug.

  # End of Bug Analysis for ${file}.
  `;
