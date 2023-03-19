/***************************************************************************//**
  file         echo.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the echo command.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Includes:
#include "../include/commands.h"
#include "../include/utils.h"
#include <stdio.h>

// Function to handle the echo command
void echo(char* args[]) {
    int i = 1;
    // Loop through the arguments and print them
    while(args[i] != NULL) {
        printf("%s ", args[i]);
        i++;
    }
    printf("\n");
}
