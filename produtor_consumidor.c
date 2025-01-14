#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include "buffer.h"

void *produtor(void *parametro) {
    buffer_item item;

    while (true) {
        sleep(rand() % 3 + 1);
        item = rand();

        if (insert_item(item)) {
            fprintf(stderr, "Erro ao produzir item\n");
        } else {
            printf("Produtor produziu: %d\n", item);
        }
    }
}

void *consumidor(void *parametro) {
    buffer_item item;

    while (true) {
        sleep(rand() % 3 + 1);

        if (remove_item(&item)) {
            fprintf(stderr, "Erro ao consumir item\n");
        } else {
            printf("Consumidor consumiu: %d\n", item);
        }
    }
}