#!/usr/bin/env bash

# Generate test input in a temporary directory and copy one produced file
# to the requested target path in the package root
#
# Arguments:
#   parameter 1 - trusted generator shell command, executed inside the temporary directory
#   parameter 2 - target test input file path relative to the package root
#   parameter 3 - test index
#
# Notes:
# - parameter 1 is executed via eval and therefore must be trusted
# - In normal usage, doall.sh is expected to generate parameter 1 safely

fail() {
    echo "$1"
    read -r
}

require_non_empty_arg() {
    local parameter_name="$1"
    local parameter_value="$2"

    if [ -z "$parameter_value" ]
    then
        fail "$parameter_name is empty"
    fi
}

readonly generator_command="$1"
readonly target_path="$2"
readonly generated_file="$3"
readonly temp_dir="tmp-for-input-generation"

require_non_empty_arg "First parameter" "$generator_command"
require_non_empty_arg "Second parameter" "$target_path"
require_non_empty_arg "Third parameter" "$generated_file"

# Remove the previous target file before generating a new one
rm -f -- "$target_path"

# Recreate the temporary working directory from scratch
rm -rf -- "$temp_dir"

(
    mkdir -- "$temp_dir" && cd -- "$temp_dir" || {
        fail "Failed to enter temporary directory"
    }

    # Run the generator inside the temporary directory
    if ! eval "$generator_command"
    then
        fail "The command '$generator_command' was executed, but it returned a non-zero exit code."
    fi

    # Copy the generated file back to the requested target path.
    if ! cp -- "$generated_file" "../$target_path"
    then
        fail "Can't copy $generated_file to ../$target_path"
    fi

    # Double-check that the target file really exists after copying.
    if [ ! -f "../$target_path" ]
    then
        fail "Can't find ../$target_path"
    fi
)

# Remove the temporary working directory after generation is complete.
rm -rf -- "$temp_dir"
