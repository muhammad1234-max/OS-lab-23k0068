#include <stdio.h>
#include <unistd.h>

int main() {
    printf("node:1 , pid = %d, ppid =%d\n", getpid(), getppid());
    int i = fork();
    
    if (i == 0) {
        printf("node:3 , pid = %d, ppid =%d\n", getpid(), getppid());
    } else {
        i = fork();
        if (i == 0) {
            printf("node:2 , pid = %d, ppid =%d\n", getpid(), getppid());
            i = fork();
            if (i == 0) {
                printf("node:6 , pid = %d, ppid =%d\n", getpid(), getppid());
            }
        } else {
            i = fork();
            if (i == 0) {
                printf("node:5 , pid = %d, ppid =%d\n", getpid(), getppid());
            }
        }
    }
    
    return 0;
}
