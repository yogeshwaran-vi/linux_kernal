#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
int main()
{
	int fd1,fd2;
	char str1[100],str2[100];
	char ch;
	int fs = open("temp.txt",O_RDONLY);
        mkfifo("fifo3",0644);
	mkfifo("fifo4",0644);
	perror("fifo3");
	fd1=open("fifo3",O_WRONLY);
	fd2=open("fifo4",O_RDONLY);
//	printf("hii...\n");
	if((fd1<0)||(fd2<0))
	{
		perror("open");
		return 0;
	}	
	if(fork()==0)
	{
		while(1)
		{
			read(fd2,str1,sizeof(str1));
			printf("%s\n",str1);
		}
	}
	else
	{
		while(1)
		{
			while(read(fs,&ch,1)>0)
				write(fd1,&ch,sizeof(ch));
		}
	}
		
}

