/***************************************************************************//**
  file         parser.h
  author       Fiachra Gill
  sid          21444356
  date         March 2023
*******************************************************************************/

#ifndef PARSER_H
#define PARSER_H

/**
 * This function parses a command string into arguments
 * 
 * @param command a string containing the command to parse
 * @return an array of strings containing the parsed arguments, with the last element set to NULL
 */
char** parse_command(char* command);

#endif /* PARSER_H */
