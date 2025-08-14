#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d running\n", id);
    pthread_exit((void*)arg); // Return the thread id as exit status
}

int main() {
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};
    void* status;

    for(int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }
    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], &status);
        printf("Thread %d terminated\n", *(int*)status);
    }
    return 0;
}