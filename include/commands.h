/***************************************************************************//**
  file         commands.h
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This is the header file for commands that are used in the shell.
*******************************************************************************/

#ifndef COMMANDS_H
#define COMMANDS_H

void dir(char **args);
void pause_operations();
void cd(char *args[], int argc);
void environ_list();
void help();
void echo(char* args[]);
int set_var(char **args);

#endif // COMMANDS_H
