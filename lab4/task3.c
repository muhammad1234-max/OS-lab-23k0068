#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Create and write to a file
    fd = open("testfile.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("File creation failed");
        exit(1);
    }
    write(fd, "Hello, system calls!\n", 21);
    close(fd);

    // Open and read the file
    fd = open("testfile.txt", O_RDONLY);
    if (fd < 0) {
        perror("File open failed");
        exit(1);
    }
    read(fd, buffer, sizeof(buffer));
    printf("File content: %s\n", buffer);
    close(fd);

    return 0;
}
