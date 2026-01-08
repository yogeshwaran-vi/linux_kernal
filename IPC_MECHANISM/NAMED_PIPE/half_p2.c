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
		read(fd,str1,sizeof(str1));
                printf("read:%s",str1);
		printf("\n");
		printf("write\n");
                scanf("%s",str2);
                write(fd,str2,strlen(str2)+1);
		sleep(1);
	}
}
