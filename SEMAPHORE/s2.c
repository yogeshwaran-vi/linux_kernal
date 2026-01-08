#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sem.h>
int main()
{
	char a[20]="abcdefghi";
	int fd=open("new.txt",O_WRONLY|O_CREAT|O_APPEND,0664);
	int id=semget(5,1,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	int ret,i;
	struct sembuf v;
	v.sem_num = 0;
	v.sem_flg = 0;
	v.sem_op  = 0;
	semop(id,&v,1);
	printf("entering into critical section of the code\n");
	printf("Process-1 writing the data into a file\n");
	semctl(id,0,SETVAL,1);
	for(i=0;a[i];i++)
	{
		write(fd,a+i,1);
		sleep(1);
		printf("%c ",a[i]);
	}
	printf("process 2 completed\n");
	semctl(id,0,SETVAL,0);
}
