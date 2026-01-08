#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/signal.h>
#include<sys/shm.h>
#include<fcntl.h>
int *p;
void isr(int n)
{
	printf("In isr(), n = %d\n",n);
	shmdt(p);
	printf("*p = %d\n",*p);
}
int main()
{
	int id,time;
	srand(getpid());
	time = rand()%10+1;
	printf("alarm is set for %d seconds\n",time);
	alarm(time);
	signal(SIGALRM,isr);
	id = shmget(11,20,IPC_CREAT|0664);
	if(id<0) 
	{
        perror("shmget");
        return 0;
        }
	printf("segment created..\n");
	p = shmat(id,0,0);
	while(1); 
}
