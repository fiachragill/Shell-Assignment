#include "commands.h"

void dir() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\t\n", dir->d_name);
        }
    }
}

void pause_operations() {
    printf("Press enter to continue...");
    getchar();
}

void cd(char *args[], int argc) {
    char *dir = args[1];
    char cwd[1024];

    if(dir == NULL) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd() error");
        }
    }
    else if (strcmp(dir, "..") == 0) {
        if(chdir("..") == 0) {
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                setenv("PWD", cwd, 1);
            } else {
                perror("getcwd() error");
            }
        }
        // Error handling. Incase 'chdir' fails.
        else {
            printf("Failed to change directory.\n");
        }
    }
    else {
        if(chdir(dir) == 0) {
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                setenv("PWD", cwd, 1);
            } else {
                perror("getcwd() error");
            }
        }
        else {
            // Error handling. If the directory does not exist, report an appropriate error
            printf("Directory '%s' does not exist.\n", dir);
        }
    }
}

extern char **environ;

void environ_list() {;
	for (char **environments = environ; *environments != NULL; environments++) {
		printf("%s\n", *environments);
	}
}

void help() {
	system("more ../man/readme.md");
}