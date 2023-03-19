/***************************************************************************//**
  file         utils.h
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This is the header file for the utils that are used in the shell.
*******************************************************************************/

#ifndef UTILS_H
#define UTILS_H

void execute_command(char **args);
int handle_input_redirection(char **args, int *input_fd);
int handle_output_redirection(char **args, int *output_fd);

#endif // UTILS_H
