#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

void dir();
void pause_operations();
void cd(char *args[], int argc);
void echo(char* args[], int argc);
void environ_list();
void help();

#endif // COMMANDS_H    