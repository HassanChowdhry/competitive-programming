#!/bin/bash

# Path to your executable (change if needed)
EXEC="./main"

input="test.inp"

# Output file
output="test.out"

echo "Running $input → $output"

# Run main and redirect output
$EXEC < "$input" > "$output"

echo "All testcases processed."

