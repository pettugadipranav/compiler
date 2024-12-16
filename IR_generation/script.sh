#!/bin/bash

passed=0
failed=0

# Take files using find command with the specified pattern
while IFS= read -r file; do
    # Run the executable ./a.out by taking input from $file and capture the output
    echo "************** New Test case  *****************"

    # Check if the file exists
    if [ -e "$file" ]; then
        echo "Running test case: ${file}"

        # Run the executable ./a.out by taking input from $file and capture the output
        output=$(./a.out "$file" 2>&1)

        # Check for errors in the captured output
        if [[ $output != *"Syntactically correct!"* ]]; then
            failed=$((failed + 1))
            echo "Test Case: ${file%.*}, status: Failed"
        else
            passed=$((passed + 1))
            echo "Test Case: ${file%.*}, status: Passed"
        fi

        # Write the captured output to a log file
        echo "$output" > "${file%.*}_log.txt"
        echo "Last line of output: $(echo "$output" | tail -n 1)"
    else
        echo "File not found: ${file}"
        failed=$((failed + 1))
    fi
done < <(find ./testcases -type f -regex ".*t[0-9]+\.txt")

printf "Exit Status: \n"
echo "Passed: $passed/$((passed + failed))"
echo "Failed: $failed/$((passed + failed))"
