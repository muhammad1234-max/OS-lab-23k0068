#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

int main() {
    float *A, *B, *C;
    A = (float*) malloc(SIZE * sizeof(float));
    B = (float*) malloc(SIZE * sizeof(float));
    C = (float*) malloc(SIZE * sizeof(float));

    // Initialize arrays with sample values
    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0;
        B[i] = i * 2.0;
    }

    // Perform addition
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }

    // Print some results
    printf("C[0] = %f, C[9999999] = %f\n", C[0], C[SIZE - 1]);

    // Free memory
    free(A);
    free(B);
    free(C);

    return 0;
}
