/***************************************************************************//**
  file         environ_list.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the environ command.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Includes:
#include "../include/commands.h"
#include "../include/utils.h"
#include <stdio.h>

// external variable for the environment
extern char **environ;

// Function to handle the environ command
// Function to handle the environ command
void environ_list() {
    // Loop through the environment variables and print them
    for (char **environments = environ; *environments != NULL; environments++) {
        printf("%s\n", *environments);
    }
}
