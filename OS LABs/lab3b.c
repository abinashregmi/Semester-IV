#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX_READERS 5
sem_t rw_mutex;
sem_t mutex;
int reader_count = 0;int read_batch = 0;
void* reader(void* arg) {
 int id = *((int*)arg);
 free(arg);
 sem_wait(&mutex);
 reader_count++;
 if (reader_count == 1) {
 sem_wait(&rw_mutex);
 }
 sem_post(&mutex);
 printf("Reader %d is reading...\n", id);
 sleep(1);
 sem_wait(&mutex);
 reader_count--;
 read_batch++;
 if (reader_count == 0) {
 sem_post(&rw_mutex);
 }
 if (read_batch == MAX_READERS) {
 printf("5 readers have read. Writer can write now.\n");
 read_batch = 0;
}
 sem_post(&mutex);
 pthread_exit(NULL);
}
void* writer(void* arg) {
 int id = *((int*)arg);
 free(arg);
 sem_wait(&rw_mutex);
 printf("Writer %d is writing...\n", id);
 sleep(2);
sem_post(&rw_mutex);
 pthread_exit(NULL);
}
int main() {
 pthread_t r[10], w[2];
 sem_init(&rw_mutex, 0, 1);
 sem_init(&mutex, 0, 1);
 for (int i = 0; i < 10; i++) {
 int* id = malloc(sizeof(int));
 *id = i + 1;
 pthread_create(&r[i], NULL, reader, id);
 sleep(1);
 }
 for (int i = 0; i < 2; i++) {
 int* id = malloc(sizeof(int));
 *id = i + 1;
 pthread_create(&w[i], NULL, writer, id);
 sleep(5);
 }
 for (int i = 0; i < 10; i++) {
 pthread_join(r[i], NULL);
 }
 for (int i = 0; i < 2; i++) {
 pthread_join(w[i], NULL);
 }
 sem_destroy(&rw_mutex);
 sem_destroy(&mutex
 printf("@AbinashRegmi")
 return 0;
}