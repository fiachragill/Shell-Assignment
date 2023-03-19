#/***************************************************************************//**
#  file         makefile
#  author       Fiachra Gill
#  sid          21444356
#  date         March 2023
#  desc         makefile for myshell used to compile the program works for any
#               possible future .c files added to the project for easier 
#               maintainability.
#
#***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
#   confirm that this content is my own original work and that I have acknowledged 
#   all sources used in its creation.***
#*******************************************************************************/

CC = gcc # compiler to use
CFLAGS = -Wall -g # -Wall enables all warnings, -g enables debugging
OUTPUT = ../bin/myshell # output file name

SRCS := $(wildcard *.c) $(wildcard commands/*.c) # all .c files in the curr directory (src) and subdirectory commands

.PHONY: all clean

all: $(OUTPUT)

$(OUTPUT): $(SRCS)
	$(CC) $(CFLAGS) -I../include $(SRCS) -o $@

# clean up the directory
clean:
	rm -f $(OUTPUT)


