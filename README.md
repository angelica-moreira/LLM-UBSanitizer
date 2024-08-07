# Static Analyzer with LLMs for Undefined Behavior

## Overview

This project provides a static analysis tool that detects and addresses undefined behavior (UB) in programs. The tool utilizes Large Language Models (LLMs) to enhance traditional static analysis, offering suggestions and validating fixes using LLVM tools.

## Process Flow

The process consists of the following steps:

1. **Static Analysis Tool**: Use a static analysis tool to check for undefined behavior (UB) in the original program.
2. **LLM Static Analysis**: Apply an LLM model to reason about the code and act as an additional static analyzer to discover undefined behavior.
3. **Comparison of Results**: Compare the results from both the static analysis tool and the LLM. Create a comparison table to track whether both methods identified the same UB, and document any discrepancies.
4. **Generate LLVM-IR**: Use Clang to generate the LLVM Intermediate Representation (LLVM-IR) from the original program.
5. **LLM Suggestion and Application**: Ask the LLM to suggest a solution for the identified UB. Apply the suggested solution to a copy of the program and generate a new LLVM-IR using Clang.
6. **Verification with Alive2**: Use Alive2 to check both LLVM-IR versions are semantically equal. If Alive2 finds the change acceptable, suggest the modified code to the user; otherwise, reject the change.

## Flowchart

![Process Flowchart](images/flowchart.jpeg)

## Installation

To get started with the project, clone this repository and follow the instructions below.
