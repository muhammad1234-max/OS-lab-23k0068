#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000000
#define THREADS 10

float *A, *B, *C;

typedef struct {
    int start, end;
} ThreadData;

// Function executed by each thread
void* add_arrays(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    for (int i = data->start; i < data->end; i++) {
        C[i] = A[i] + B[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    ThreadData threadData[THREADS];

    // Allocate memory
    A = (float*) malloc(SIZE * sizeof(float));
    B = (float*) malloc(SIZE * sizeof(float));
    C = (float*) malloc(SIZE * sizeof(float));

    // Initialize arrays
    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0;
        B[i] = i * 2.0;
    }

    // Create threads
    int chunk_size = SIZE / THREADS;
    for (int i = 0; i < THREADS; i++) {
        threadData[i].start = i * chunk_size;
        threadData[i].end = (i == THREADS - 1) ? SIZE : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, add_arrays, &threadData[i]);
    }

    // Join threads
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print some results
    printf("C[0] = %f, C[9999999] = %f\n", C[0], C[SIZE - 1]);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}
