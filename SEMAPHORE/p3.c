#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sem.h>
int main()
{
	char a[]="abcdefghij";
	int fd=open("temp.txt",O_CREAT|O_WRONLY|O_APPEND,0664);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	int id=semget(5,3,IPC_CREAT|0664),i;
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	struct sembuf v;
	v.sem_num=0;
	v.sem_op=-1;
	v.sem_flg=0;
	
	semop(id,&v,1);
	printf("p3 start writing...\n");
	
	for(i=0;a[i];i++)
	{
		write(fd,a+i,1);
		sleep(1);
	}
	v.sem_op=1;
	semop(id,&v,1);
	printf("p3 completed...\n");
}
