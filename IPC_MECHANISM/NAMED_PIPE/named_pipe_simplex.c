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
	//printf("hi...\n");
	fd=open("fifo",O_WRONLY);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	while(1)
	{
		printf("write:");
		scanf("%s",str);
		write(fd,str,strlen(str)+1);
	}
}
