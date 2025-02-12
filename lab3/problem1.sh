#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <directory> <new_name_pattern>"
    exit 1
fi

DIR=$1
PATTERN=$2

if [ ! -d "$DIR" ]; then
    echo "Error: Directory '$DIR' not found!"
    exit 1
fi

COUNT=1

for FILE in "$DIR"/*; do
    if [ -f "$FILE" ]; then
        EXT="${FILE##*.}"
        NEW_NAME="${PATTERN}${COUNT}.${EXT}"
        mv "$FILE" "$DIR/$NEW_NAME"
        echo "Renamed: $FILE -> $NEW_NAME"
        ((COUNT++))
    fi
done

echo "Renaming complete."
