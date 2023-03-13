CC = gcc
CFLAGS = -Wall -g
OUTPUT = ../bin/myshell

myshell: main.c utils.c parser.c exec.c builtin.c parser.h
	$(CC) $(CFLAGS) main.c utils.c parser.c exec.c builtin.c -o $(OUTPUT)

clean:
	rm -f $(OUTPUT) *.o
