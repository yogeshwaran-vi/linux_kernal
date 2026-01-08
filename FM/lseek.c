#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
        char a[100];
       int fd = open("temp.txt",O_RDONLY);
        if(fd < 0)
        {
                printf("f = %d\n",fd);
                perror("open");
               return 0;
        }
        char ch;
        read(fd,&ch,1);
        //int ret=lseek(fd,5,SEEK_SET);
       // int ret=lseek(fd,5,SEEK_CUR);
        int ret = lseek(fd,-5,SEEK_END);
        printf("ret = %d\n",ret);
        read(fd,&ch,1);
        printf("ch = %c\n",ch);
}
