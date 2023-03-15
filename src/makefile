CC = gcc
CFLAGS = -Wall -g
OUTPUT = ../bin/myshell

myshell: main.c utils.c parser.c commands.c commands.h parser.h
	$(CC) $(CFLAGS) main.c utils.c parser.c commands.c -o $(OUTPUT)

clean:
	rm -f $(OUTPUT) *.o
