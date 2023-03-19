/***************************************************************************//**
  file         dir.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the dir command.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

#include "../include/commands.h"
#include "../include/utils.h"
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

// Function to handle the dir command
void dir(char **arguments) {
    DIR *d;
    struct dirent *entry;
    d = opendir(".");

    if (d) {
        int input_fd = -1;
        int output_fd = -1;

        // Handle input and output redirection
        handle_input_redirection(arguments, &input_fd);
        handle_output_redirection(arguments, &output_fd);

        // If output redirection is used, redirect stdout to the output file descriptor
        if (output_fd != -1) { 
            dup2(output_fd, STDOUT_FILENO); 
            close(output_fd);
        }

        // Read the entries in the directory and print them to stdout
        while ((entry = readdir(d)) != NULL) {
            // Using d_type from the dirent structure to check if the entry is a directory
            if (entry->d_type == DT_DIR) {
                printf("DIR  \t%s\n", entry->d_name);
            } else {
                printf("FILE\t%s\n", entry->d_name);
            }
        }
        closedir(d);
    }
}
