#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./getval <sem_num>\n");
		return 0;
	}

	int id=semget(5,3,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	int sem_num=atoi(argv[1]);
	int ret=semctl(id,sem_num,GETVAL);
	printf("getval:%d\n",ret);
}
