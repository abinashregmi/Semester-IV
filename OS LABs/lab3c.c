#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define CHAIRS 3

sem_t customers, barber, mutex;
int waiting = 0;

void* barber_func(void* arg) {
    while (1) {
        sem_wait(&customers); // Wait for a customer
        sem_wait(&mutex);
        waiting--;
        sem_post(&barber);    // Barber is ready
        sem_post(&mutex);
        printf("Barber is cutting hair\n");
        sleep(2);
    }
    return NULL;
}

void* customer_func(void* arg) {
    sem_wait(&mutex);
    if (waiting < CHAIRS) {
        waiting++;
        printf("Customer sits. Waiting: %d\n", waiting);
        sem_post(&customers); // Notify barber
        sem_post(&mutex);
        sem_wait(&barber);    // Wait for barber
        printf("Customer is getting haircut\n");
    } else {
        sem_post(&mutex);
        printf("Customer leaves (no chair)\n");
    }
    return NULL;
}

int main() {
    pthread_t b, c[5];
    sem_init(&customers, 0, 0);
    sem_init(&barber, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&b, NULL, barber_func, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_create(&c[i], NULL, customer_func, NULL);
        sleep(1);
    }
    for (int i = 0; i < 5; i++) pthread_join(c[i], NULL);
    return 0;
}