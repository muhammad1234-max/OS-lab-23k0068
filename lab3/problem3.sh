#!/bin/bash

TIME_PERIOD=5  # Default time period (seconds)
OUTPUT_FILE="sys_report.txt"

while getopts "t:o:" opt; do
    case $opt in
        t) TIME_PERIOD=$OPTARG ;;
        o) OUTPUT_FILE=$OPTARG ;;
        *) echo "Usage: $0 [-t time_period] [-o output_file]"; exit 1 ;;
    esac
done

echo "Monitoring system for $TIME_PERIOD seconds..."
sleep $TIME_PERIOD

CPU_USAGE=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')
MEM_USAGE=$(free -m | awk '/Mem:/ {printf "%.2f", $3/$2 * 100}')
DISK_USAGE=$(df -h / | awk 'NR==2 {print $5}')
NET_TRAFFIC=$(ifstat 1 1 | awk 'NR==3 {print "RX: " $1 " KB/s, TX: " $2 " KB/s"}')

echo -e "System Monitoring Report\n------------------------" > "$OUTPUT_FILE"
echo "CPU Usage: $CPU_USAGE%" >> "$OUTPUT_FILE"
echo "Memory Usage: $MEM_USAGE%" >> "$OUTPUT_FILE"
echo "Disk Usage: $DISK_USAGE" >> "$OUTPUT_FILE"
echo "Network Traffic: $NET_TRAFFIC" >> "$OUTPUT_FILE"

echo "Monitoring complete. Report saved to $OUTPUT_FILE."
