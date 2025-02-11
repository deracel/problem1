CC = gcc
CFLAGS = -c -Wall

all: example

example: inoutput.o main.o task.o
		$(CC) inoutput.o main.o task.o -o example

inoutput.o: inoutput.c
		$(CC) $(CFLAGS) inoutput.c

main.o: main.c
		$(CC) $(CFLAGS) main.c

task.o: task.c
		$(CC) $(CFLAGS) task.c

clean:
		rm -rf *.o example

.PHONY: all clean
