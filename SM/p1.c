#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
int main()
{
	int id,*p; 
	id=shmget(4,20,IPC_CREAT|0664);
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	printf("segment created\n");
	p=shmat(id,0,0);
	while(1)
	{
		printf("%d\n",*p);
		sleep(1);
	}
	shmdt(p);
}
