#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd1;
	fd1=open("temp4.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd1<0) {
		perror("open");
		return 0;
	}
	close(1);
	dup(fd1);
	execlp("date","date",NULL);
	printf("after execlp\n");
}
