#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10

int array[SIZE];

void *sort_first_half(void *arg) {
    for (int i = 0; i < SIZE / 2 - 1; ++i)
        for (int j = 0; j < SIZE / 2 - i - 1; ++j)
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
    pthread_exit(NULL);
}

void *sort_second_half(void *arg) {
    for (int i = SIZE / 2; i < SIZE - 1; ++i)
        for (int j = SIZE / 2; j < SIZE - 1 - (i - SIZE / 2); ++j)
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
    pthread_exit(NULL);
}

void merge_sorted_halves() {
    int temp[SIZE];
    int i = 0, j = SIZE / 2, k = 0;

    while (i < SIZE / 2 && j < SIZE) {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i < SIZE / 2) temp[k++] = array[i++];
    while (j < SIZE) temp[k++] = array[j++];

    for (i = 0; i < SIZE; ++i)
        array[i] = temp[i];
}

int main() {
    pthread_t t1, t2;

    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");

    pthread_create(&t1, NULL, sort_first_half, NULL);
    pthread_create(&t2, NULL, sort_second_half, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    merge_sorted_halves();

    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
