#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CUSTOMERS 5

pthread_mutex_t order_mutex;
sem_t chef_semaphore;
int order_id = 0;

void *customer_thread(void *arg) {
    pthread_mutex_lock(&order_mutex);
    int my_order = ++order_id;
    printf("Customer %ld placed order #%d\n", (long)arg, my_order);
    pthread_mutex_unlock(&order_mutex);

    sem_wait(&chef_semaphore); // Wait for chef
    printf("Chef started preparing order #%d\n", my_order);
    sleep(2); // Simulate cooking
    printf("Chef completed order #%d\n", my_order);
    sem_post(&chef_semaphore); // Chef becomes available again

    return NULL;
}

int main() {
    pthread_t customers[NUM_CUSTOMERS];
    pthread_mutex_init(&order_mutex, NULL);
    sem_init(&chef_semaphore, 0, 2); // 2 chefs available

    for (long i = 0; i < NUM_CUSTOMERS; i++)
        pthread_create(&customers[i], NULL, customer_thread, (void *)i);

    for (int i = 0; i < NUM_CUSTOMERS; i++)
        pthread_join(customers[i], NULL);

    pthread_mutex_destroy(&order_mutex);
    sem_destroy(&chef_semaphore);
    return 0;
}
