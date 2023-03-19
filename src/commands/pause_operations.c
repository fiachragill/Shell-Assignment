/***************************************************************************//**
  file         pause_operations.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the pause command.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Includes:
#include "../include/commands.h"
#include "../include/utils.h"
#include <stdio.h>

// Function to handle the pause command
void pause_operations() {
    // Prompt the user to press enter to continue
    printf("Press enter to continue...");
    // Wait for the user to press enter
    getchar();
}
