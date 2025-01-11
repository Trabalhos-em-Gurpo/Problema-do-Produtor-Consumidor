#include <stdlib.h> /* necessário para rand() */

#include "buffer.h"

void *produtor(void *parâmetro)
{

    buffer_item item;

    while (true)
    {

        /* dormir por um período aleatório */

        sleep(...);

        /* gerar um número aleatório */

        item = rand();

        if (insert_item(item))

            fprintf("condição de erro de relatório");

        else

            printf("produtor produziu %d\n", item);
    }
}

void *consumidor(void *parâmetro)
{

    buffer_item item;

    while (true)
    {

        /* dormir por um período aleatório de tempo */

        sleep(...);

        if (remove_item(&item))

            fprintf("condição de erro de relatório");

        else

            printf("consumidor consumido %d\n", item);
    }
}