#!/usr/bin/env bash

# Generate several test inputs in a temporary directory and copy them
# to the requested target paths in the package root
#
# Arguments:
#   parameter 1 - trusted generator shell command, executed inside the temporary directory
#   parameter 2 - target test input file paths relative to the package root, separated by ':'
#   parameter 3 - generated file indices, separated by ':'
#
# Notes:
# - parameter 1 is executed via eval and therefore must be trusted
# - In normal usage, doall.sh is expected to generate parameter 1 safely
# - Generated files are looked up by index first, then by zero-padded variants

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

copy_generated_file() {
    local source_index="$1"
    local destination_path="$2"

    cp -- "$source_index" "$destination_path" 2> /dev/null ||
    cp -- "0$source_index" "$destination_path" 2> /dev/null ||
    cp -- "00$source_index" "$destination_path" 2> /dev/null
}

readonly generator_command="$1"
readonly target_paths_raw="$2"
readonly indices_raw="$3"
readonly temp_dir="tmp-for-input-generation"

require_non_empty_arg "First parameter" "$generator_command"
require_non_empty_arg "Second parameter" "$target_paths_raw"
require_non_empty_arg "Third parameter" "$indices_raw"

# Split colon-separated argument lists into bash arrays
IFS=':' read -r -a target_paths <<< "$target_paths_raw"
IFS=':' read -r -a indices <<< "$indices_raw"

# Make sure each requested target path has a matching generated file index
if [ "${#target_paths[@]}" -ne "${#indices[@]}" ]
then
    fail "The number of target paths does not match the number of indices"
fi

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

    for (( i = 0; i < ${#target_paths[@]}; i++ ))
    do
        rm -f -- "../${target_paths[$i]}"

        # Try the raw index first, then zero-padded variants.
        if ! copy_generated_file "${indices[$i]}" "../${target_paths[$i]}"
        then
            fail "Can't copy ${indices[$i]} to ../${target_paths[$i]}"
        fi

        # Double-check that the target file really exists after copying
        if [ ! -f "../${target_paths[$i]}" ]
        then
            fail "Can't find ../${target_paths[$i]}"
        fi

        echo "Test #${indices[$i]} has been generated and copied to ${target_paths[$i]}"
    done
)

# Remove the temporary working directory after generation is complete
rm -rf -- "$temp_dir"
