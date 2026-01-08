#include <stdio.h>
#include <sys/shm.h>
int main()
{
	int id = shmget(5,10,IPC_CREAT|0664);
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	printf("shmget id:%d\n",id);
}
