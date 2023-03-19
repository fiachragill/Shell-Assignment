/***************************************************************************//**
  file         help.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the help command.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Includes:
#include "../include/commands.h"
#include "../include/utils.h"
#include <stdlib.h>

// Function to handle the help command
void help() {
    // Show user manual
    system("more ../man/readme.md");
}