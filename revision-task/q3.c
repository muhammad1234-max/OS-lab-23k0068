#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_TELLERS 3
#define NUM_CUSTOMERS 10

int balance = 1000;
pthread_mutex_t lock;

void *teller(void *arg) {
    for (int i = 0; i < NUM_CUSTOMERS / NUM_TELLERS; ++i) {
        pthread_mutex_lock(&lock);
        int transaction = (rand() % 200) - 100; // Deposit or withdraw
        balance += transaction;
        printf("Teller %ld processed transaction: %d, New balance: %d\n", (long)arg, transaction, balance);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t tellers[NUM_TELLERS];
    pthread_mutex_init(&lock, NULL);

    for (long i = 0; i < NUM_TELLERS; i++)
        pthread_create(&tellers[i], NULL, teller, (void *)i);

    for (int i = 0; i < NUM_TELLERS; i++)
        pthread_join(tellers[i], NULL);

    pthread_mutex_destroy(&lock);
    printf("Final balance: %d\n", balance);
    return 0;
}
