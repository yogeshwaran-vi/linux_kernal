// process2.c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    int fd1, fd2;
    char filedata[100], word[50], rev[50];

    mkfifo("fifo3", 0664);
    mkfifo("fifo4", 0664);

    fd1 = open("fifo3", O_RDONLY); 
    fd2 = open("fifo4", O_WRONLY); 
   
    read(fd1, filedata, sizeof(filedata));
    printf("File Data: %s\n", filedata);

    printf("Enter word to reverse: ");
    scanf("%s", word);

    char*pos=strstr(filedata,word);

    if (strstr(filedata, word) != NULL)
    {
        int len = strlen(word);
        for(int i=0; i<len; i++)
            rev[i] = word[len-i-1];
        rev[len] = '\0';

	memcpy(pos,rev,len);
    }
    else
    {
        write(fd2, "Word not found", 15);
    }
    write(fd2,filedata, strlen(filedata)+1);
}

