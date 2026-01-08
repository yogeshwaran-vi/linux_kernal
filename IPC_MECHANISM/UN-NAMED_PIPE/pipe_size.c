#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	char ch='A';
	int fd[2],count=0;

	if(pipe(fd)<0)
	{
		perror("pipe");
		return 0;
	}

	while((write(fd[1],&ch,1)) !=-1)
	{
		count++;
		printf("sizeof pipe = %d\n",count);
	}
}
