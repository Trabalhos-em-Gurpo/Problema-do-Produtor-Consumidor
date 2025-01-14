# makefile for thread pool
#

CC=gcc
CFLAGS=-Wall
PTHREADS=-lpthread

all: buffer.o produtor_consumidor.o main.o
	$(CC) $(CFLAGS) -o produtor_consumidor main.o produtor_consumidor.o buffer.o $(PTHREADS)

produtor_consumidor.o: produtor_consumidor.c produtor_consumidor.h
	$(CC) $(CFLAGS) -c produtor_consumidor.c $(PTHREADS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(PTHREADS)

buffer.o: buffer.c buffer.h
	$(CC) $(CFLAGS) -c buffer.c $(PTHREADS)

clean:
	rm -rf *.o
	rm -rf produtor_consumidor