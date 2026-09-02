#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char command[100];
    char *args[20];
    int i = 0;

    printf("Enter command: ");
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = 0;

    args[0] = strtok(command, " ");

    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " ");
    }

    int pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        execvp(args[0], args);
    }
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        wait(NULL);
        printf("Child process completed.\n");
    }

    return 0;
}
