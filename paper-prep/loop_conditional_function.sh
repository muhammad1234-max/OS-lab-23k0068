#!/bin/bash

# Function to check if a number is even or odd
check_even_odd() {
    num=$1  # First argument
    if (( num % 2 == 0 )); then
        echo "$num is even."
    else
        echo "$num is odd."
    fi
}

# Function to find the factorial of a number using recursion
factorial() {
    if [ $1 -le 1 ]; then
        echo 1
    else
        prev=$(factorial $(( $1 - 1 )))  # Recursive call
        echo $(( $1 * prev ))
    fi
}

# Function to demonstrate case statement
show_day_type() {
    case $1 in
        "Saturday"|"Sunday")
            echo "$1 is a weekend."
            ;;
        "Monday"|"Tuesday"|"Wednesday"|"Thursday"|"Friday")
            echo "$1 is a weekday."
            ;;
        *)
            echo "Invalid day!"
            ;;
    esac
}

# Using a FOR loop to iterate through a list
echo "Numbers from 1 to 5:"
for i in {1..5}; do
    echo -n "$i "
done
echo ""

# Using a WHILE loop to count down from 5
echo "Countdown using while loop:"
count=5
while [ $count -gt 0 ]; do
    echo -n "$count "
    ((count--))
done
echo ""

# Using an UNTIL loop to count up to 5
echo "Counting up using until loop:"
num=1
until [ $num -gt 5 ]; do
    echo -n "$num "
    ((num++))
done
echo ""

# Calling functions
echo "Checking if 7 is even or odd:"
check_even_odd 7

echo "Factorial of 5:"
factorial 5

echo "Checking day type for Friday:"
show_day_type "Friday"
