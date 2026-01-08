#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	int fd[2];
	if(pipe(fd)<0)
	{
		perror("pipe");
		return 0;
	}
	printf("fd[0]=%d fd[1]=%d\n",fd[0],fd[1]);
	if(fork()==0)
	{
		
		char a[20],a1[20];
		while(1)
		{
			read(fd[0],a,sizeof(a));
			printf("in child received msg:%s\n",a);
			printf("in child sent msg\n");
			scanf("%s",a1);
			write(fd[1],a1,strlen(a1)+1);
			sleep(1);
		}
	}
	else
	{
			char b[20],b1[20];
			while(1)
			{
				printf("in parent sent msg:");
				scanf("%s",b);
				write(fd[1],b,strlen(b)+1);
				sleep(1);
				read(fd[0],b1,sizeof(b1));
				printf("in parent received msg:%s\n",b1);
			}
	}
}
