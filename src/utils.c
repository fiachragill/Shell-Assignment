/***************************************************************************//**
  file         utils.c
  author       Fiachra Gill
  sid          21444356
  date         March 2023
  descr        This file contains the implementation of the utility functions
               that are used by the shell. These functions handle I/O redirection,
               background process execution, and command execution.

***I have read and understood the DCU Academic Integrity and Plagiarism Policy. I
   confirm that this content is my own original work and that I have acknowledged 
   all sources used in its creation.***
*******************************************************************************/

// Includes:
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h> // for open(), close(), O_RDONLY, dup(), etc.

// This function handles input redirection (stdin) by searching for '<' in the arguments
// and opening the file to read from it. It also updates the arguments to remove the redirection.
int handle_input_redirection(char **arguments, int *input_fd) {
    // Iterate through the arguments
    for (int i = 0; arguments[i] != NULL; i++) {
        // Check if the current argument is the input redirection symbol '<'
        if (strcmp(arguments[i], "<") == 0) {
            // Open the file for reading (O_RDONLY)
            *input_fd = open(arguments[i+1], O_RDONLY);
            // If the file couldn't be opened, print an error message and return 1 (error)
            if (*input_fd < 0) {
                fprintf(stderr, "Error: could not open input file.\n");
                return 1;
            }
            // Update the arguments to remove the input redirection and the file name
            arguments[i] = NULL;
            arguments[i+1] = NULL;
            // Return 0 (success) since input redirection was handled
            return 0;
        }
    }
    // Return 0 (success) if no input redirection was found
    return 0;
}

// This function handles output redirection (stdout) by searching for '>' or '>>' in the arguments,
// opening the file for writing or appending, and updating the arguments to remove the redirection.
int handle_output_redirection(char **arguments, int *output_fd) {
    // Iterate through the arguments
    for (int i = 0; arguments[i] != NULL; i++) {
        // Check if the current argument is the output redirection symbol '>'
        if (strcmp(arguments[i], ">") == 0) {
            // Open the file for writing, create if it does not exist, and truncate it (O_WRONLY | O_CREAT | O_TRUNC)
            *output_fd = open(arguments[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            // If the file couldn't be opened, print an error message and return 1 (error)
            if (*output_fd < 0) {
                fprintf(stderr, "Error: could not open output file.\n");
                return 1;
            }
            // Update the arguments to remove the output redirection and the file name
            arguments[i] = NULL;
            arguments[i+1] = NULL;
            // Return 0 (success) since output redirection was handled
            return 0;
        }
        // Check if the current argument is the output redirection symbol '>>'
        else if (strcmp(arguments[i], ">>") == 0) {
            // Open the file for appending, create if it does not exist (O_WRONLY | O_CREAT | O_APPEND)
            *output_fd = open(arguments[i+1], O_WRONLY | O_CREAT | O_APPEND, 0644);
            // If the file couldn't be opened, print an error message and return 1 (error)
            if (*output_fd < 0) {
                fprintf(stderr, "Error: could not open output file.\n");
                return 1;
            }
            // Update the arguments to remove the output redirection and the file name
            arguments[i] = NULL;
            arguments[i+1] = NULL;
            // Return 0 (success) since output redirection was handled
            return 0;
        }
    }
    // Return 0 (success) if no output redirection was found
    return 0;
}

// This function checks if a given command should be executed as a background process.
// It searches for '&' in the arguments and removes it from the arguments if found.
int is_background_process(char **arguments) {
    for (int i = 0; arguments[i] != NULL; i++) {
        if (strcmp(arguments[i], "&") == 0) {
            arguments[i] = NULL;  // Remove the '&' from the arguments
            return 1;
        }
    }
    return 0;
}

// This function is called by the child process to execute the command, redirect I/O if needed,
// and set an environment variable for the parent shell.
void execute_child_process(char **arguments, int input_fd, int output_fd) {
    // If input redirection is requested, duplicate the input file descriptor to stdin and close the original
    if (input_fd != -1) {
        dup2(input_fd, STDIN_FILENO);
        close(input_fd);
    }
    // If output redirection is requested, duplicate the output file descriptor to stdout and close the original
    if (output_fd != -1) {
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);
    }

    // Set the parent environment variable
    setenv("parent", "/myshell", 1);

    // Execute the command using execvp. If it fails, print an error message and exit the child process.
    if (execvp(arguments[0], arguments) < 0) {
        perror(arguments[0]);
        exit(1);
    }
}

// This function is called by the parent process to manage the child process execution.
// It waits for the child to finish if it's a foreground process, or prints the process ID for background processes.
void execute_parent_process(pid_t pid, int background) {
    if (!background) {
        // If not a background process, wait for the child to finish
        int status;
        waitpid(pid, &status, 0);
    } else {
        // If a background process, print the process ID
        printf("Background process started with PID %d\n", pid);
    }
}

// This function is the main entry point to execute a command.
// It checks if the command should run in the background, handles I/O redirection, and forks the process to execute the command.
void execute_command(char **arguments) {
    int background = is_background_process(arguments);
    int input_fd = -1;
    int output_fd = -1;

    // Handle I/O redirection
    if (handle_input_redirection(arguments, &input_fd) || handle_output_redirection(arguments, &output_fd)) {
        return;
    }

    // Fork the process and execute the command
    pid_t pid = fork();

    if (pid < 0) {
        // If the fork failed, print an error message and return
        perror("Fork failed");
        return;
    }

    if (pid == 0) {
        // Child process
        execute_child_process(arguments, input_fd, output_fd);
    } else {
        // Parent process
        execute_parent_process(pid, background);
    }
}

