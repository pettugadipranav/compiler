#!/bin/bash
file="input.cplex"
echo $file
$(./a.out $file 2>&1)
if [[ $output == *"error"* ]]; then
    echo "Test Case: ${file%.*}, status: Failed"
else
    echo "Test Case: ${file%.*}, status: Passed"
fi
echo $output
# echo $output > "${file%.*}_log.txt"
