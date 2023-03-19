========================================================================================
[2019-05-20 16:00:00] [INFO] [Shell-Assignment]: # Path: Shell-Assignment\man\readme.md
========================================================================================

SHELL MANUAL

NAME
       myshell - Simple UNIX Shell

SYNOPSIS
       myshell [batchfile]

DESCRIPTION
       MyShell is a simple UNIX shell designed for basic command execution, I/O redirection, and background program execution.
       This manual provides an overview of the shell's functionality, as well as instructions for using it.

OPTIONS
       batchfile
                 If batchfile is present, the shell processes the set of command lines from the specified file. When the end-of-file
                 is reached, the shell exits. If the shell is invoked without a command line argument, it solicits input from the
                 user via a prompt on the display.

                 >>> ./myshell <batchfile-name>

SHELL FEATURES
       

        Program Environment
                 The program environment in MyShell consists of environment variables, which are key-value pairs that provide information about the system and user preferences. These variables can be accessed and modified using the 'environ' command. They are inherited from the parent process and can affect the behavior of programs executed within the shell.

                 For example, the PATH variable specifies the directories in which the shell looks for executable files. To view the current value of the PATH variable, use the 'environ' command:

                 >>> environ

                 To modify an environment variable, you can use the 'set' command, followed by the variable name, an equal sign, and the new value:

                 >>> set VARIABLE_NAME=new_value
        
        Basic Commands
                 MyShell supports basic UNIX commands, such as cd, dir, echo, pause, environ, help, and clr. To execute a command, type it at the
                 prompt and press Enter:

                 >>> command [arguments]

        List of Basic Commands:

                 - cd: Change the current working directory
                   Example: >>> cd /home/user/documents
                            >>> cd .. (to go up one directory)

                 - dir: List the contents of a directory
                   Example: >>> dir /home/user/documents

                 - echo: Print the specified arguments to the console
                   Example: >>> echo "Hello, World!"

                 - pause: Pause the shell and wait for the user to press Enter
                   Example: >>> pause

                 - environ: List the environment variables
                   Example: >>> environ

                 - help: Display a help message with a list of supported commands
                   Example: >>> help

                 - clr: Clear the terminal screen
                   Example: >>> clr

                - quit: Exit the shell
                   Example: >>> quit

       I/O Redirection
                 MyShell supports input and output redirection using the <, >, and >> operators:

                 - <: Redirects the input of a command from a file
                 - >: Redirects the output of a command to a file, overwriting its contents
                 - >>: Redirects the output of a command to a file, appending to its contents

                 For example, to redirect the input of the sort command from input.txt and the output to output.txt, use the
                 following command:

                 >>> sort < input.txt > output.txt

       Background Program Execution
                 To execute a program in the background, append an ampersand (&) to the command. The shell will not wait for the
                 background process to finish before accepting new commands:

                 >>> command [arguments] &

       Batch Mode
                 MyShell supports batch mode, which allows it to process a set of command lines from a file. To use batch mode, pass
                 the batch file as a command line argument:

                 ./myshell batchfile

                 When the end-of-file is reached, the shell will exit.

REFERENCES
       [1]  G. Healy (DCU), Building A Shell slides (2023) "A simple shell".
            (Baisis for my main.c code.)
       [1] B. Molay, Understanding Unix/Linux Programming. Prentice Hall, 2003. 
           (Utils.c code was adapted from this book.)
       [2] Richard Stevens, Stephen A. Rago, Advanced Programming in the UNIX Environment, 3rd Edition, Addison-Wesley, 2013.
           (parser.c code was adapted from this book.)
       [3] Neil Matthew, Richard Stones, Beginning Linux Programming, 4th Edition, Wiley, 2007.
           (dir.c code was adapted from this book.)
       [4] Robert Love, Talking Directly to the Kernel and C Library, 2nd Edition, O'Reilly, 2013.
           (cd.c code was adapted from this book.)
       [5] Robert Mecklenburg, Managing Projects with GNU Make, 3rd Edition, O'Reilly, 2004.
           (Makefile code was adapted from this book.)

AUTHOR
       Fiachra Gill

ACADEMIC INTEGRITY
       This project was completed as part of my Operating Systems module in DCU. I have read and understood the DCU Academic Integrity and Plagiarism Policy. I confirm that this content is my own original work and that I have acknowledged all sources used in its creation.

========================================================================================
[2019-05-20 16:00:00] [INFO] [Shell-Assignment]: # Path: Shell-Assignment\man\readme.md
========================================================================================
