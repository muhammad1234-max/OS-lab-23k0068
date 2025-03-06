#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_FILE "/tmp/myfifo"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes;

    // Open the named pipe for reading (consumer)
    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read data from the FIFO
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        if (num_bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Null-terminate the received message
        buffer[num_bytes] = '\0';

        // Display the received message
        printf("Consumer: Received message: %s", buffer);

        // Check for exit condition
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    close(fd); // Close the named pipe
    return 0;
}
