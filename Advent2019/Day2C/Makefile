CC=cc --std=c99 -g

all: index

index: index.c helpers.o
	$(CC) index.c helpers.o -o run

helpers.o: helpers.c helpers.h
	$(CC) -c helpers.c

clean:
	rm -f run helpers.o