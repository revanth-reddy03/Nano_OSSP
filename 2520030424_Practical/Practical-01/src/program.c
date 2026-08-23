#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT 100

int main() {
    char input[MAX_INPUT];
    char *args[MAX_INPUT / 2 + 1];
    int i = 0;

    printf("Enter a Linux command: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Split command into arguments
    char *token = strtok(input, " ");

    while (token != NULL && i < MAX_INPUT / 2) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;

    printf("\nParent Process PID: %d\n", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child Process PID: %d\n", getpid());
        printf("Executing command...\n");

        execvp(args[0], args);

        // This executes only if execvp fails
        perror("execvp failed");
        exit(1);
    }
    else {
        // Parent process
        printf("Parent waiting for child process...\n");

        wait(NULL);

        printf("Child process %d completed.\n", pid);
        printf("Parent process %d completed.\n", getpid());
    }

    return 0;
}
