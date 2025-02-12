#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {  // Child process
        execlp("ls", "ls", NULL);
        perror("Exec failed");
        exit(1);
    } else {  // Parent process
        wait(NULL);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}
