#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
         struct st
         {
                 char ch;
                 int x;
                 float f;
                 char s[20];
         }v = {'A',1234,22.7,"Vector India"}; 
int main()
{
	 int fd = open("new.txt",O_WRONLY|O_CREAT|O_TRUNC,0664); 
	 write(fd,&v,sizeof(v));
}
