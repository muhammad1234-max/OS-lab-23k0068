#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd;
    char buffer[100];

    // Open file input.txt for reading and writing (create if it doesn't exist)
    fd = open("input.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Read file contents
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0) {
        perror("Error reading file");
        close(fd);
        return 1;
    }
    buffer[bytesRead] = '\0';

    // Create child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        return 1;
    } 
    else if (pid == 0) { 
        // Child process
        const char *newContent = "Processed by child process\n";
        lseek(fd, 0, SEEK_SET); // Move file pointer to start
        write(fd, newContent, sizeof(newContent));
        close(fd);

        // Replace child process with 'cat' command to display file content
        execlp("cat", "cat", "input.txt", NULL);
        perror("execlp failed");
        exit(1);
    } 
    else { 
        // Parent process
        wait(NULL); // Wait for child to finish
        close(fd);
    }

    return 0;
}
