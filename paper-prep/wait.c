#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        wait(NULL);
        sleep(10);
        printf("\n Parent");
        printf("\n PID is %d", getpid());
    }

    if (pid == 0) {
        printf("\n Child");
        printf("\n PID is %d", getpid());
        printf("\n Parent PID is %d", getppid());
    }

    return 0;
}
