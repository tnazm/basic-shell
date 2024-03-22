#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>

void cd(char *path);
void pwd();
void help();
void make_dir(char *path);
void remove_dir(char *path);
void ls(char *path);
void cp(char *src, char *dest);
void mv(char *src, char *dest);
void rm(char *path);

int main() {
    char input[1024];
    bool shouldContinue = true;

    while (shouldContinue) {
	printf("myshell> ");
        fgets(input, 1024, stdin);
	const int MAX_ARGS = 4;

	input[strcspn(input, "\n")] = 0;

        char *token = strtok(input, " ");
        char *command;
	char *args[MAX_ARGS];
        char *arg1;
	int arg_num = 0;

	/* Tokenize input into a list of arguments */
	for (int i = 0; token != NULL && i < MAX_ARGS; i++) {
	    args[i] = token;
	    arg_num++;

	    token = strtok(NULL, " ");
	}

        command = args[0];
	arg1 = args[1];
        
	if (strcmp(command, "cd") == 0) {
	    if (arg_num == 2) {
		cd(arg1);		
            } else {
		printf("Usage: cd <directory>\n");
	    }
	}
	else if (strcmp(command, "pwd") == 0) {
	    pwd();
	}
	else if (strcmp(command, "exit") == 0) {
	    shouldContinue = false;
	}
	else if (strcmp(command, "help") == 0) {
	    help();
	}
	else if (strcmp(command, "mkdir") == 0) {
	    if (arg_num == 2) {
		make_dir(arg1);		
            } else {
		printf("Usage: mkdir <directory>\n");
	    }
	}
	else if (strcmp(command, "rmdir") == 0) {
	    if (arg_num == 2) {
		remove_dir(arg1);		
            } else {
		printf("Usage: rmdir <directory>\n");
	    }
	}
	else if (strcmp(command, "ls") == 0) {
	    if (arg_num < 3) {
		ls(arg1);		
            } else {
		printf("Usage: ls <directory>\n");
	    }
	}
	else if (strcmp(command, "cp") == 0) {
	    if (arg_num == 3) {
		cp(args[1], args[2]);
            } else {
		printf("Usage: cp <source> <destination>\n");
	    }
	}
	else if (strcmp(command, "mv") == 0) {
	    if (arg_num == 3) {
		mv(args[1], args[2]);
            } else {
		printf("Usage: mv <source> <destination>\n");
	    }
	}
	else if (strcmp(command, "rm") == 0) {
	    if (arg_num == 2) {
		rm(arg1);
            } else {
		printf("Usage: rm <file>");
	    }
	}
	else {
	    printf("Unknown command: %s\n", command);
	}
    }

    return 0;
}

void cd(char *path) {
    chdir(path);
}

void pwd() {
    const int size = 256;
    char working_dir[size];
    getcwd(working_dir, size);
    printf("%s\n", working_dir);
}

void help() {
    printf("cd <directory> - change directory\n"
	   "pwd - print working directory\n"
	   "exit - exit the shell\n"
	   "help - display help\n"
	   "mkdir <directory> - create a directory\n"
	   "rmdir <directory> - remove a directory\n"
	   "ls <directory> - list files in a directory\n"
	   "cp <source> <destination> - copy a file\n"
	   "mv <source> <destination> - move a file\n"
	   "rm <file> - remove a file\n");
}

void make_dir(char *path) {
    mkdir(path, S_IRWXU);
}

void remove_dir(char *path) {
    rmdir(path);
}
void ls(char *path) {
    if (path == NULL) {
	path = ".";
    }
    DIR *dir = opendir(path);
    struct dirent* child;
    child = (struct dirent*) readdir(dir);
    while (child != NULL) {
	printf("%s\n", child->d_name);
	child = (struct dirent*) readdir(dir);
    }
    closedir(dir);
}
/* todo */
void cp(char *src, char *dest) {
    
}

void mv(char *src, char *dest) {
    rename(src, dest);
}
void rm(char *path) {
    unlink(path);
}

