#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    printf("Before fork\n");
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());

    pid = fork();

    if (pid == 0)
    {
        printf("\nChild Process\n");
        printf("PID: %d\n", getpid());
        printf("PPID: %d\n", getppid());
        printf("State: Running\n");
    }
    else if (pid > 0)
    {
        printf("\nParent Process\n");
        printf("PID: %d\n", getpid());
        printf("PPID: %d\n", getppid());
        printf("State: Running\n");
    }
    else
    {
        printf("Fork failed\n");
    }

    return 0;
}
