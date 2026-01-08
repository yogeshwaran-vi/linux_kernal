#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	char ch='A';
	int fd[2],count=0;

	pipe2(fd,O_NONBLOCK);

	while(write(fd[1],&ch,1) !=-1)
	count++;

	printf("pipe size = %d\n",count);
	
}
