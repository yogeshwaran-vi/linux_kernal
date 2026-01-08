#include <stdio.h>
#include<stdlib.h>
#include <sys/sem.h>
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage:./getval <sem_num> <sem_val>\n");
		return 0;
	}

	int id=semget(5,3,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	int sem_num=atoi(argv[1]);
	int sem_val=atoi(argv[2]);
	semctl(id,sem_num,SETVAL,sem_val);
	return 0;
}
