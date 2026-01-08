#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
int main()
{
	int fd1,fd2;
	char str1[20],str2[20];
	mkfifo("fifo1",0644);
	mkfifo("fifo2",0644);
	perror("fifo");
	fd1=open("fifo1",O_RDONLY);
	fd2=open("fifo2",O_WRONLY);
	if((fd1<0) || (fd2<0))
	{
		perror("open");
		return 0;
	}
	if(fork()==0)
	{
		while(1)
		{
			read(fd1,str1,sizeof(str1));
			printf("receive:%s\n",str1);
		}
	}
	else
	{
		while(1)
		{
			printf("sent:\n");
                	scanf("%s",str2);
                	write(fd2,str2,strlen(str2)+1);
		}
	}

}

