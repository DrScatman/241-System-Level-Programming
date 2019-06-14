CFLAGS= -g -Wall -Wextra
main: main.o list.o
	gcc main.o list.o -o main
main.o: main.c list.h
list.o: list.c list.h

test: 1
1:
	./main sample.c ids.out