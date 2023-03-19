/***************************************************************************//**
  file         set.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the setvar command.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Include necessary header files
#include <stdlib.h>
#include <stdio.h>
#include "../include/commands.h"

// set_var function takes an array of arguments and sets an environment variable
// Returns 0 on success, 1 otherwise
int set_var(char **args) {
    // Check if there are enough arguments (variable name and value)
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "set: expected two arguments\n");
        return 1;
    }

    // Set the environment variable with the given name and value, overwriting
    // any existing value. If the operation fails, print an error message.
    if (setenv(args[1], args[2], 1) != 0) {
        perror("setenv failed");
        return 1;
    }

    // Return 0 if the environment variable was set successfully
    return 0;
}
