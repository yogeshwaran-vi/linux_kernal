#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd1,fd2;
	fd1 = open("temp5.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd1 < 0) {
		perror("open");
		return 0;
	}
	fd2 = dup2(fd1,5); //3 and 5 refering to same descriptor.
	//fd2 = dup2(fd1,1); //3 and 1 refering to same descriptor.
	printf("fd2 = %d\n",fd2);
	printf("Hello...\n");
	write(fd1,"Vector",6);
	write(fd2,"Embedded",8);
}
