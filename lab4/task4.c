#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int input_fd, output_fd;
    char buffer[1024];
    ssize_t bytesRead;

    input_fd = open("input.txt", O_RDONLY);
    if (input_fd < 0) {
        perror("Error opening input file");
        exit(1);
    }

    output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd < 0) {
        perror("Error opening output file");
        close(input_fd);
        exit(1);
    }

    while ((bytesRead = read(input_fd, buffer, sizeof(buffer))) > 0) {
        write(output_fd, buffer, bytesRead);
    }

    close(input_fd);
    close(output_fd);

    printf("File copied successfully.\n");

    return 0;
}
