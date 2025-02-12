#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int signum) {
    printf("Alarm signal received!\n");
}

int main() {
    printf("Current Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());

    signal(SIGALRM, alarm_handler);  // Set up an alarm signal handler
    alarm(5);  // Set an alarm for 5 seconds
    printf("Sleeping for 3 seconds...\n");
    sleep(3);  // Sleep for 3 seconds
    printf("Woke up! Waiting for alarm...\n");
    pause();  // Wait for the alarm signal

    return 0;
}
