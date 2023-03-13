/***************************************************************************//**
  file         parser.h
  author       Fiachra Gill
  sid          21444356
  date         March 2023
*******************************************************************************/

#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>

// Maximum number of arguments allowed in a command line
#define MAX_ARGS 20
// Maximum length of an argument
#define MAX_ARG_LEN 50
// Maximum length of the input string
#define MAX_INPUT_LEN 200

// Struct to hold the parsed command line input
typedef struct {
    char* args[MAX_ARGS];
    int argc;
    bool background;
    bool pipe;
    bool redirect;
} Command;

// Parse the input string into a Command struct
void parse_input(const char* input, Command* command);

#endif