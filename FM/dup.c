#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd1,fd2;
	printf("pid = %d\n",getpid());
	fd1 = open("temp3.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd1 < 0) {
		perror("open");
		return 0;
	}
	//close(2);
	fd2 = dup(fd1);
	printf("fd1 = %d\n",fd1);
	printf("fd2 = %d\n",fd2);
	write(fd1,"hello",5);
	write(fd2,"india",5);
}
