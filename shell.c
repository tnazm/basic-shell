#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cd(char *path);

int main() {
    char input[1024];

    while (1) {
        printf("myshell> ");
        fgets(input, 1024, stdin);

        input[strcspn(input, "\n")] = 0;

        char *command = strtok(input, " ");
        char *arg1 = strtok(NULL, " ");
        // You can extend this code to support more arguments

        if (strcmp(command, "cd") == 0) {
            cd(arg1);
        }
        // You will need to extend this code to support other commands
        else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}

void cd(char *path) {
    // Placeholder for 'cd' implementation
}

// The remaining functions can be implemented here
