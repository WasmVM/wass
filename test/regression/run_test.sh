#!/bin/bash
wass=$1
input_file=$2
output_file=$3
expect_file=$4

$wass $input_file -o $output_file
result=$?
if [ $result -ne 0 ]; then
    exit $result
fi

diff $output_file $expect_file
exit $?
