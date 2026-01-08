#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int ret;
	open("data.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
	write(3,"Vector\n",7);
	//ret = fcntl(3,F_GETFD);
	printf("FD_CLOEXEC bit value : %d\n",ret);
	ret = fcntl(3,F_SETFD,1);
	 ret = fcntl(3,F_GETFD);
	printf("FD_CLOEXEC bit value : %d\n",ret);

	execlp("./p1","p1",NULL);
	write(3,"Embedded\n",9);
	printf("Current process terminated...\n");
}
