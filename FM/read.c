#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd;
	char ch;
	fd=open("temp.txt",O_RDONLY);
	if(fd<0)
	{
		printf("fd=%d\n",fd);
		perror("open");
		return 0;
	}
	while(read(fd,&ch,1)>0)		
		printf("ch=%c\n",ch);	
}
