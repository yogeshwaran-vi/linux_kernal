#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <fcntl.h>
int main()
{
	int i;
	char s[]="at perungudi in channai ";
	int fd=open("data.txt",O_CREAT|O_WRONLY|O_APPEND,0664);
	if(fd<0){
		perror("open");
		return 0;
	}
	int id=semget(5,3,IPC_CREAT|0664);
	if(id<0){
		perror("semget");
		return 0;
	}
	struct sembuf v[2]={{0,0,0},{2,-1,SEM_UNDO}};
	semop(id,v+1,1);
	printf("allowed to access the resource...\n");
	semop(id,v,1);
	semctl(id,0,SETVAL,1);
	printf("p4 written into the file...\n");
	for(i=0;s[i];i++)
	{
		write(fd,s+i,1);
		sleep(1);
	}
	semctl(id,0,SETVAL,0);
	printf("p4 write is completed...\n");
	close(fd);
	sleep(5);
	printf("p4 terminated...\n");
}
