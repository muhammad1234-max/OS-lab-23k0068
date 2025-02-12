#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {  // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        execlp("/bin/ls", "ls", NULL);  // Execute 'ls' command
        perror("Exec failed");
        exit(1);
    } else {  // Parent process
        wait(NULL);  // Wait for child to finish
        printf("Parent Process: PID = %d\n", getpid());
    }

    return 0;
}
