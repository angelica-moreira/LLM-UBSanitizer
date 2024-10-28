#!/bin/bash

# Check if a directory is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

# Get the directory from the command line argument
DIRECTORY="$1"

# Check if the directory exists
if [ ! -d "$DIRECTORY" ]; then
    echo "Error: Directory '$DIRECTORY' does not exist."
    exit 1
fi

# Find and delete .log and .ll files
echo "Deleting .log and .ll files in '$DIRECTORY' and its subdirectories..."
find "$DIRECTORY" -type f \( -name "*.log" -o -name "*.ll" -o -name "*.json" \) -exec rm -f {} +

echo "Cleanup completed."

