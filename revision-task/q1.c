#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

FILE *tempFile;

void cleanup(int sig) {
    if (tempFile) {
        fclose(tempFile);
        remove("tempfile.txt");
        printf("\nTemporary file closed and deleted. Exiting...\n");
    }
    exit(0);
}

int main() {
    signal(SIGINT, cleanup);
    tempFile = fopen("tempfile.txt", "w");

    if (!tempFile) {
        perror("Failed to create file");
        return 1;
    }

    int count = 0;
    while (1) {
        fprintf(tempFile, "Writing line %d\n", ++count);
        fflush(tempFile);
        printf("Line %d written.\n", count);
        sleep(1);
    }

    return 0;
}
