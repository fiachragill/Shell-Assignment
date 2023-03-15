/***************************************************************************//**
  file         main.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

#include "commands.h"
#include "parser.h"

#define MAX_BUFFER 1024                       // max line buffer
#define SEPARATORS " \t\n"                     // token separators

int main (int argc, char ** argv)
{
    char buf[MAX_BUFFER];                      // line buffer
    char ** args;                              // pointers to arg strings
    char * prompt = ">>>" ;                    // shell prompt
    /* keep reading input until "quit" command or eof of redirected input */

    while (!feof(stdin)) { 
        /* get command line from input */
        fputs (prompt, stdout); // write prompt

        if (fgets (buf, MAX_BUFFER, stdin )) { // read a line
            /* tokenize the input into args array */
            args = parse_command(buf);

            if (args[0]) {                     // if there's anything there
                /* check for internal/external command */
                if (!strcmp(args[0],"clr")) { // "clear" command
                    system("clear");
                    continue;
                }

                if (!strcmp(args[0],"quit")) {  // "quit" command
                    printf("exiting shell...\n");  
                    break;                     // break out of 'while' loop
                }
                /* else pass command onto OS */
                if (!strcmp(args[0],"dir")||!strcmp(args[0],"ls")) {  // "dir" command
                    dir();
                    continue;
                }
                if (!strcmp(args[0],"pause")) {  // "pause" command
                    pause_operations();
                    continue;
                }
                if (!strcmp(args[0],"cd")) {  // "cd" command
                    cd(args, 2);
                    continue;
                }
                if (!strcmp(args[0],"environ")||!strcmp(args[0],"env")) {  // "help" command
                    environ_list();
                    continue;
                }
                if (!strcmp(args[0],"help")) {  // "help" command
                    help();
                    continue;
                }

                fprintf(stderr, "Command not found: %s\n", args[0]);
            }

            free(args);  // Remember to free the memory allocated by parse_command()
        }
    }
    return 0; 
}
