#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <directory> <days>"
    exit 1
fi

DIR=$1
DAYS=$2

if [ ! -d "$DIR" ]; then
    echo "Error: Directory '$DIR' not found!"
    exit 1
fi

# Delete files older than the specified number of days
FILES_REMOVED=$(find "$DIR" -type f -mtime +$DAYS -print -delete | wc -l)

# Remove empty directories
DIRS_REMOVED=$(find "$DIR" -type d -empty -print -delete | wc -l)

echo "Cleanup complete: Removed $FILES_REMOVED files and $DIRS_REMOVED empty directories."
