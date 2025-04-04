#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numbers[] = {90, 81, 78, 95, 79, 72, 85};
int size = 7;

typedef struct {
    int result;
} ThreadResult;

// Function to compute average
void* compute_average(void* arg) {
    ThreadResult* res = (ThreadResult*) malloc(sizeof(ThreadResult));
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    res->result = sum / size;
    pthread_exit(res);
}

// Function to compute maximum
void* compute_maximum(void* arg) {
    ThreadResult* res = (ThreadResult*) malloc(sizeof(ThreadResult));
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    res->result = max;
    pthread_exit(res);
}

// Function to compute minimum
void* compute_minimum(void* arg) {
    ThreadResult* res = (ThreadResult*) malloc(sizeof(ThreadResult));
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    res->result = min;
    pthread_exit(res);
}

int main() {
    pthread_t threads[3];
    ThreadResult *avgResult, *maxResult, *minResult;

    // Create threads
    pthread_create(&threads[0], NULL, compute_average, NULL);
    pthread_create(&threads[1], NULL, compute_maximum, NULL);
    pthread_create(&threads[2], NULL, compute_minimum, NULL);

    // Wait for threads to finish and collect results
    pthread_join(threads[0], (void**)&avgResult);
    pthread_join(threads[1], (void**)&maxResult);
    pthread_join(threads[2], (void**)&minResult);

    // Print results
    printf("The average value is %d.\n", avgResult->result);
    printf("The maximum value is %d.\n", maxResult->result);
    printf("The minimum value is %d.\n", minResult->result);

    // Free memory
    free(avgResult);
    free(maxResult);
    free(minResult);

    return 0;
}
