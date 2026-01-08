#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
void*thread1(void*);
void*thread2(void*);
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	printf("thread1 t1 id = %ld\n",t1);
	printf("thread2 t2 id = %ld\n",t2);
	printf("in main()....\n");
	printf("infinite process...\n");
	while(1);
}
void*thread1(void*p)
{
	printf("in thread1...\n");
	sleep(5);
	printf("exit thread1...\n");
}
void*thread2(void*p)
{
	printf("in thread2...\n");
	sleep(8);
	printf("exit thread2...\n");
}

