#include <pthread.h>
#include "buffer.h"

buffer_item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

int insert_item(buffer_item item) {
    pthread_mutex_lock(&mutex);

    while (count == BUFFER_SIZE) {
        pthread_cond_wait(&empty, &mutex);
    }

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;

    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);

    return 0;
}

int remove_item(buffer_item *item) {
    pthread_mutex_lock(&mutex);

    while (count == 0) {
        pthread_cond_wait(&full, &mutex);
    }

    *item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;

    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&mutex);

    return 0;
}