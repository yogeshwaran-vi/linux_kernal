#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
void *thread1(void *);
void *thread2(void *);
char s[30],r[30];
int id1,id2;
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	while(1);
}
void *thread1(void*p)
{
	mkfifo("fifo1",0664);
	id1=open("fifo1",O_RDWR);
	if(id1<0)
	{
		perror("fifo");
		return 0; 
	}
	while(1)
	{
		read(id1,r,sizeof(r));
		printf("receive: %s\n",r);
	}
}
void *thread2(void*p)
{
	mkfifo("fifo2",0664);
	id2=open("fifo2",O_RDWR);
	if(id2<0)
	{
		perror("fifo");
		return 0; 
	}
	while(1)
	{
		scanf("%s",s);
		write(id2,s,strlen(s)+1);
	}
}
