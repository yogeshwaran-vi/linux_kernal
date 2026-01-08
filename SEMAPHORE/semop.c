#include <stdio.h>
#include <sys/sem.h>
int main()
{
	int id=semget(5,0,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	struct sembuf v;
	v.sem_num = 0;
	v.sem_op  = 0;
	v.sem_flg = 0;
	printf("before sem_op\n");
	semop(id,&v,1);
	printf("after sem_op\n");
	
}
