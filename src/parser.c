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
#include <stdbool.h>
#include "parser.h"

// Tokenize the input string and populate the command struct
void parse_input(const char* input, Command* command) {
    char* input_copy = strdup(input); // create a non-const copy
    char* token;
    int i = 0;

    // Initialize the command struct
    command->background = false;
    command->argc = 0;

    // Tokenize the input string
    token = strtok(input_copy, " ");

    // Loop through the tokens
    while (token != NULL) {
        // Check if the token is a special character
        if (strcmp(token, "|") == 0) {
            command->pipe = true;
        }
        else if (strcmp(token, ">") == 0) {
            command->redirect = true;
        }
        else if (strcmp(token, "&") == 0) {
            command->background = true;
        }
        // Otherwise, add the token to the command struct
        else {
            if (i < MAX_ARGS) {
                command->args[i] = token;
                i++;
            }
            else {
                fprintf(stderr, "Too many arguments. Ignoring: %s\n", token);
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Set the argument count
    command->argc = i;

    // Set the last argument to NULL
    if (i < MAX_ARGS) {
        command->args[i] = NULL;
    }

    // Free the input copy
    free(input_copy);
}
