// process1.c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd1, fd2, fs;
    char buf[100];

    mkfifo("fifo3", 0664);
    mkfifo("fifo4", 0664);

    fs = open("temp.txt", O_RDONLY);
    fd1 = open("fifo3", O_WRONLY); 
    fd2 = open("fifo4", O_RDONLY);

    int n = read(fs, buf, sizeof(buf));
    buf[n] = '\0';
    write(fd1, buf, strlen(buf)+1);

    read(fd2, buf, sizeof(buf));
    printf("Reversed word from P2:\n %s\n", buf);
}

