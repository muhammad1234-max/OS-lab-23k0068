#!/bin/bash

# Check if a filename is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

# Count and display the number of lines in the file
if [ -f "$1" ]; then
    line_count=$(wc -l < "$1")
    echo "Number of lines in $1: $line_count"
else
    echo "File not found!"
fi
