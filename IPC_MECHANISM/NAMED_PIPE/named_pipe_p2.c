#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd;
	char str[50];
	mkfifo("fifo",0644);
	perror("mkfifo");
//	printf("hii...");
	fd=open("fifo",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	while(1)
	{
		int ret=read(fd,str,sizeof(str));
		printf("read:%s",str);
		//printf("ret:%d",ret);
		printf("\n");
	}
}
