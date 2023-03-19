/***************************************************************************//**
  file         main.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the main function and loop of the shell. It is 
               responsible for reading input from the user and calling the appropriate
               functions to execute the commands.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Includes:
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

#include "../include/commands.h"
#include "../include/utils.h"
#include "../include/parser.h"

// Defines:
#define MAX_BUFFER 1024                       // max line buffer
#define SEPARATORS " \t\n"                     // token separators

int main (int argc, char ** argv)
{
    char buf[MAX_BUFFER];                      // line buffer
    char ** args;                              // pointers to arg strings
    char * prompt = ">>>" ;                    // shell prompt

    // Check if a batch file is provided as an argument
    FILE *input = stdin;
    if (argc > 1) {
        input = fopen(argv[1], "r"); // Open the file for reading
        if (!input) {
            fprintf(stderr, "Error: Unable to open batch file %s\n", argv[1]);
            exit(1);
        }
    }

    /* keep reading input until "quit" command or eof of redirected input */
    while (!feof(input)) { 
        // Display the prompt and read a line
        if (input == stdin) {
            fputs (prompt, stdout); // write prompt
        }

        if (fgets (buf, MAX_BUFFER, input)) { // read a line
            // Tokenize the input into the args array
            args = parse_command(buf);

            // If there's any command in the input
            if (args[0]) {
                // Check for internal commands
                if (!strcmp(args[0], "clr")) { // "clear" command
                    system("clear");
                } else if (!strcmp(args[0], "quit")) { // "quit" command
                    printf("exiting shell...\n");
                    break;
                } else if (!strcmp(args[0], "dir")) { // "dir" command
                    dir(args);
                } else if (!strcmp(args[0], "pause")) { // "pause" command
                    pause_operations();
                } else if (!strcmp(args[0], "cd")) { // "cd" command
                    cd(args, 2);
                } else if (!strcmp(args[0], "environ")) { // "environ" command
                    environ_list();
                } else if (!strcmp(args[0], "help")) { // "help" command
                    help();
                } else if (!strcmp(args[0], "echo")) { // "echo" command
                    echo(args);
                } else if (!strcmp(args[0], "set")) { // "set" command
                    set_var(args);
                } else {
                    // External command
                    execute_command(args);
                }

                free(args); // free the memory allocated by parse_command()
            }
        }
    }

    // Close the file if it was opened
    if (argc > 1) {
        fclose(input);
    }

    return 0; 
}
