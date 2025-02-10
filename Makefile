CC = gcc
CFALGS = -c -Wall

all: example

example: inoutput.o main.o
		$(CC) inoutput.o main.o -o example

inoutput.o: inoutput.c
		$(CC) $(CFALGS) inoutput.c

main.o: main.c
		$(CC) $(CFALGS) main.c

clean:
		rm -rf *.o example

.PHONY: all clean
