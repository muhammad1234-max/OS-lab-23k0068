#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int PID;
    char cmd[256];

    printf("Press e if you want to terminate\n");

    while (1) {
        printf("cmd: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "e") == 0)  /* Loop terminates if 'e' is typed */
            exit(0);

        /* Creates a new process. Parent gets the process ID, child gets 0 */
        if ((PID = fork()) > 0) {
            wait(NULL);
        } else if (PID == 0) {  /* Child process */
            execlp(cmd, cmd, NULL);
            /* exec cannot return. If it does, do the following */
            fprintf(stderr, "Cannot execute %s\n", cmd);
            exit(1);  /* exec failed */
        } else if (PID == -1) {
            fprintf(stderr, "Cannot create a new process\n");
            exit(2);
        }
    }
}
