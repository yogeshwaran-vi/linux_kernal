#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sem.h>
int main()
{
	char a[20]="123456789";
	int fd = open("new.txt",O_WRONLY|O_CREAT|O_APPEND,0664);
	int id=semget(5,1,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	int ret;
	struct sembuf v;
	v.sem_num = 0;
	v.sem_flg = 0;
	v.sem_op  = -1;
	semop(id,&v,1);
	write(fd,a,strlen(a)+1);	
	v.sem_op  = +1;
	semop(id,&v,1);
	printf("process 2 completed\n");
}
