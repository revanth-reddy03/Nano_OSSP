#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int f1, f2;
    char data[100];
    int n;

    f1 = open("file1.txt", O_RDONLY);
    f2 = open("file2.txt", O_WRONLY | O_CREAT, 0644);

    n = read(f1, data, 100);
    write(f2, data, n);

    close(f1);
    close(f2);

    printf("File copied successfully");
}
