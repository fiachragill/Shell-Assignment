/***************************************************************************//**
  file         parser.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
*******************************************************************************/

// This code is adapted from "Building a Simple Shell in C" by Stephen Brennan:
// https://brennan.io/2015/01/16/write-a-shell-in-c/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

// Certainly! Here's an example of a command parser function that you could use to tokenize arguments in your shell program. This function is based on an online tutorial from GeeksforGeeks (https://www.geeksforgeeks.org/making-linux-shell-c/) and has been slightly modified to improve its readability.

// Tokenize the input string and populate the command struct
/**
 * This function parses a command string into arguments
 * 
 * @param command a string containing the command to parse
 * @return an array of strings containing the parsed arguments, with the last element set to NULL
 */
char** parse_command(char* command) {

    int buffer_size = 64;
    int position = 0;
    char** arguments = malloc(buffer_size * sizeof(char*));
    char* argument;

    if (!arguments) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    argument = strtok(command, " \t\n");
    while (argument != NULL) {
        arguments[position] = argument;
        position++;

        if (position >= buffer_size) {
            buffer_size += 64;
            arguments = realloc(arguments, buffer_size * sizeof(char*));

            if (!arguments) {
                fprintf(stderr, "Memory allocation error.\n");
                exit(EXIT_FAILURE);
            }
        }

        argument = strtok(NULL, " \t\n");
    }

    arguments[position] = NULL;
    return arguments;
}
