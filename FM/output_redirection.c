#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd;
	//close(1);
	fd=open("temp3.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd<0){
		perror("open");
		return 0;
	}
	printf("value of fd=%d\n",fd);
}
