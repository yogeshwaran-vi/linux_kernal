#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
int main()
{
	int fd1,fd2;
	char str[50],str1[100],str2[100],ch;
        mkfifo("fifo3",0644);
        mkfifo("fifo4",0644);
	perror("fifo3");

	fd1=open("fifo3",O_RDONLY);
	fd2=open("fifo4",O_WRONLY);
//	printf("hi...\n");
	if((fd1<0)||(fd2<0))
	{
		perror("open");
		return 0;
	}	
	int k;
	if(fork()==0)
	{
		while(1)
		{
			printf("enter the word to reverse");
			scanf("%s",str);
			if(strstr(str,str1)>0)
			{
				int x=strlen(str);
				for(int i=x;i>0;i--)
				{
					str2[k++]=str[i];
				}
				write(fd2,str2,strlen(str2)+1);
			}
		}
	}
	else
	{
		while(1){
		read(fd1,str1,sizeof(str1));
		printf("%s",str1);
		printf("\n");
		}
	}
}

