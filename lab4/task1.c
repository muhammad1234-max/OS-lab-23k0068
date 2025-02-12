#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;

    child1 = fork(); // First child process
    if (child1 == 0) {
        printf("Child 1: My PID is %d\n", getpid());
        exit(0);
    } 

    child2 = fork(); // Second child process
    if (child2 == 0) {
        printf("Child 2: My Parent PID is %d\n", getppid());
        exit(0);
    }

    // Parent waits for both child processes
    wait(NULL);
    wait(NULL);

    printf("Parent: Both child processes have terminated.\n");

    return 0;
}
