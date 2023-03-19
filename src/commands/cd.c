/***************************************************************************//**
  file         cd.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the cd command.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Includes:
#include "../include/commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// Function to handle the cd command
void cd(char *args[], int argc) {
    char *dir = args[1]; // Get the directory to change to
    char cwd[1024]; // Buffer to store the current working directory

    if (dir == NULL) { // If no directory is specified, change to the home directory
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd); // Print the current working directory
        } else {
            perror("getcwd() error"); // If the current working directory cannot be found, print an error
        }
    } else { // If a directory is specified, change to that directory
        if (chdir(dir) == 0) { // If the directory exists and we have permission to access it
            if (getcwd(cwd, sizeof(cwd)) != NULL) { // Get the current working directory
                setenv("PWD", cwd, 1); // set the PWD environment variable to the current working directory
            } else {
                perror("getcwd() error");
            }
        } else { // If the directory does not exist or we do not have permission to access it
            if (errno == ENOENT) {
                printf("Directory '%s' does not exist.\n", dir);
            } else if (errno == EACCES) {
                printf("Permission denied: cannot access '%s'.\n", dir);
            } else {
                perror("chdir() error");
            }
        }
    }
}
