#!/bin/bash

# megaphone_test.sh - Test script for megaphone

test_megaphone() {
    if [[ $# -eq 1 ]]; then
        local expected_output="$1"
        local output=$(./../ex00/megaphone)
    else
        local input=("$1")
        local expected_output="$2"
        local output=$(./../ex00/megaphone "${input[@]}")
    fi

    # Compare the output with the expected output
    if [[ "$output" == "$expected_output" ]]; then
        echo "[PASS] ./megaphone ${input[@]}"
    else
        echo "[FAIL] ./megaphone ${input[@]}"
        echo "  Expected: $expected_output"
        echo "  Got:      $output"
        return 1
    fi
}

# Test cases
test_megaphone "shhhhh... I think the students are asleep..." "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
test_megaphone "Damnit ! Sorry students, I thought this thing was off." "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
test_megaphone "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

# Collect results
if [[ $? -eq 0 ]]; then
    echo "All tests passed!"
    exit 0
else
    echo "Some tests failed."
    exit 1
fi
