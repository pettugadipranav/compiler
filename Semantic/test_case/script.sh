#!/bin/bash
# echo "Hello World!"
# Take all input files in current directory and run them using command gcc
passed=0;
failed=0;
#take file from ls command
# $exec
for file in ./test_case/*.cplex; do
    # Run the executable ./a.out by taking input from $file and capture the output
    echo "************** New Test case  *****************"
    output=$(./a.out $file 2>&1)
    # echo $output
    echo $file
    # Check for errors in the captured output
    if [[ $output == *"error"* ]]; then
        failed=$(($failed+1))
        echo "Test Case: ${file%.*}, status: Failed"
    else
        passed=$(($passed+1))
        echo "Test Case: ${file%.*}, status: Passed"
    fi

    # Write the captured output to a log file
    # echo $output
    echo "$output" > "${file%.*}_log.txt"
done
# rm ./a.out
printf "Exit Status: \n" ;
echo "Passed: $passed/$((passed+failed))"
echo "Failed: $failed/$((passed+failed))"
