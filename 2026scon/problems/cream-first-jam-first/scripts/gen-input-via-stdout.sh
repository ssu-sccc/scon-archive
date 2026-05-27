#!/usr/bin/env bash

# Generate test input by redirecting the generator stdout to the target file
#
# Arguments:
#   parameter 1 - trusted generator shell command
#   parameter 2 - target test input file path relative to the current directory
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

require_non_empty_arg "First parameter" "$generator_command"
require_non_empty_arg "Second parameter" "$target_path"

# Remove the previous output file before generating a new one
rm -f -- "$target_path"

# Execute the generator command and redirect stdout to the target file
if ! eval "$generator_command" > "$target_path"
then
    fail "The command '$generator_command' was executed, but it returned a non-zero exit code."
fi

if [ ! -f "$target_path" ]
then
    fail "Executed '$generator_command' > '$target_path', but it did not create the file"
fi
