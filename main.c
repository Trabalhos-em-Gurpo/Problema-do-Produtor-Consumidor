#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "buffer.h"
#include "produtor_consumidor.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <tempo_dormir> <n_produtores> <n_consumidores>\n", argv[0]);
        return -1;
    }

    int tempo_dormir = atoi(argv[1]);
    int n_produtores = atoi(argv[2]);
    int n_consumidores = atoi(argv[3]);

    pthread_t produtores[n_produtores];
    pthread_t consumidores[n_consumidores];

    for (int i = 0; i < n_produtores; i++) {
        pthread_create(&produtores[i], NULL, produtor, NULL);
    }

    for (int i = 0; i < n_consumidores; i++) {
        pthread_create(&consumidores[i], NULL, consumidor, NULL);
    }

    sleep(tempo_dormir);

    printf("Encerrando threads.\n");
    pthread_join(produtores[0], NULL);
    exit(0);
}