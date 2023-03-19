/***************************************************************************//**
  file         parser.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the parser. The parser
               takes a command string and parses it into an array of strings
               that can be used by the shell.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parses a command into arguments
char** parse_command(char* command) {
    const char* delim = " \t\n";
    int buffer_size = 64;
    int position = 0;

    // Allocate memory for the arguments
    char** arguments = malloc(buffer_size * sizeof(char*));
    char* argument;

    // Check if memory allocation was successful
    if (!arguments) {
        // If not, print an error message and exit the program
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Split the command into individual arguments using a delimiter
    while ((argument = strsep(&command, delim)) != NULL) {
        // Skip empty fields
        if (*argument == '\0') {
            continue;
        }

        // Add the argument to the arguments array
        arguments[position++] = argument;

        // Check if we need to allocate more memory for arguments
        if (position >= buffer_size) {
            buffer_size += 64;
            arguments = realloc(arguments, buffer_size * sizeof(char*));

            // Check if memory allocation was successful
            if (!arguments) {
                // If not, print an error message and exit the program
                fprintf(stderr, "Memory allocation error.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Add a NULL terminator to the end of the arguments array
    arguments[position] = NULL;

    // Return the arguments array
    return arguments;
}

