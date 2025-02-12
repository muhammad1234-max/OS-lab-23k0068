#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int signum) {
    printf("Alarm received. Terminating program.\n");
    exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(5);  // Set alarm for 5 seconds

    while (1) {
        printf("Running...\n");
        sleep(1);  // Sleep for 1 second
    }

    return 0;
}
