#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>
int main(int argc,char**argv)
{
	if(argc!=3)
	{
		printf("Usage: ./getval <sem_num> <set_val>\n");
		return 0;
	}
	int id=semget(5,3,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	printf("id:%d\n",id);
	int sem_num=atoi(argv[1]);
	int set_val=atoi(argv[2]);
	int ret=semctl(id,sem_num,SETVAL,set_val);
	printf("GETVAL ret: %d\n",ret);

}

