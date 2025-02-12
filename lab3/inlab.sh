#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <logfile>"
    exit 1
fi

LOGFILE=$1
OUTPUT_FILE="log_summary.txt"

if [ ! -f "$LOGFILE" ]; then
    echo "Error: Log file '$LOGFILE' not found!"
    exit 1
fi

# Count total number of requests
TOTAL_REQUESTS=$(wc -l < "$LOGFILE")

# Count unique IP addresses
UNIQUE_IPS=$(awk '{print $1}' "$LOGFILE" | sort | uniq | wc -l)

# Identify top 5 most frequent IP addresses
TOP_IPS=$(awk '{print $1}' "$LOGFILE" | sort | uniq -c | sort -nr | head -5)

# Calculate total size of data transferred
TOTAL_BYTES=$(awk '{sum += $NF} END {print sum}' "$LOGFILE")

# Generate summary report
echo "Web Server Log Analysis Report" > "$OUTPUT_FILE"
echo "-----------------------------------" >> "$OUTPUT_FILE"
echo "Total Requests: $TOTAL_REQUESTS" >> "$OUTPUT_FILE"
echo "Unique IP Addresses: $UNIQUE_IPS" >> "$OUTPUT_FILE"
echo "Top 5 Most Frequent IP Addresses:" >> "$OUTPUT_FILE"
echo "$TOP_IPS" >> "$OUTPUT_FILE"
echo "Total Data Transferred: $TOTAL_BYTES bytes" >> "$OUTPUT_FILE"

echo "Analysis complete. Report saved to $OUTPUT_FILE."
