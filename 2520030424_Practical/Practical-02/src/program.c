#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2;
    char buff[100];
    size_t n;

    fd1 = open("sourcefile", O_RDONLY);

    fd2 = open("destinationfile", O_WRONLY | O_CREAT, 0644);

    printf("Source file descriptor: %d\n", fd1);
    printf("Destination file descriptor: %d\n", fd2);

    n = read(fd1, buff, 100);

    write(fd2, buff, n);

    close(fd1);
    close(fd2);

    printf("File copied successfully..\n");

    return 0;
}
