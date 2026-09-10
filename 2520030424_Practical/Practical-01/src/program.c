#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char cmd[20];

    printf("Enter command: ");
    scanf("%s", cmd);

    if (fork() == 0) {
        printf("Child PID = %d\n", getpid());
        execlp(cmd, cmd, NULL);
    } else {
        printf("Parent PID = %d\n", getpid());
        wait(NULL);
    }
}
