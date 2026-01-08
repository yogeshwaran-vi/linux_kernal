#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd;
	char str1[20],str2[20];
	mkfifo("fifo",0644);
	perror("fifo");
	printf("wait..\n");
	fd=open("fifo",O_RDWR);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	while(1)
	{
		printf("write\n");
		scanf("%s",str1);
		write(fd,str1,strlen(str1)+1);
		sleep(1);
		read(fd,str2,sizeof(str2));
		printf("read:%s",str2);
		printf("\n");
	}
}
