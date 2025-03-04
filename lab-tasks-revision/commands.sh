# 1. Create a directory called project in your home directory.
mkdir ~/project

# 2. Navigate to the project directory.
cd ~/project

# 3. Create an empty file named task1.txt in the project directory.
touch task1.txt

# 4. List all files in the current directory.
ls

# 5. Create a file called file1.txt.
touch file1.txt

# 6. Change permissions of file1.txt (Owner: read & write, Others: no permission).
chmod 600 file1.txt

# 7. Check permissions of file1.txt.
ls -l file1.txt

# 8. Grant execute permission to the owner of file1.txt.
chmod u+x file1.txt

# 9. Display the current working directory.
pwd

# 10. Show the current date and time.
date

# 11. Display system’s disk usage.
df -h

# 12. Display system uptime.
uptime

# 13. Show all users currently logged into the system.
who
