#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int g=0;
pthread_mutex_t M=PTHREAD_MUTEX_INITIALIZER;    //INITIALIZER of the mutex
void*thread1(void *);
void*thread2(void *);
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	printf("infinite loop\n");
	while(1);
}
void*thread1(void *p)
{
	pthread_mutex_lock(&M);
	g++;
	printf("in thread1 g = %d\n",g);
	sleep(2);
	printf("after change g value : g = %d\n",g);
	pthread_mutex_unlock(&M);
}
void*thread2(void *p)
{
	pthread_mutex_lock(&M);
	printf("in thread2 g = %d\n",g);
	g=10;
	sleep(1);
	g++;
	printf("after change g value : g = %d\n",g);
	pthread_mutex_unlock(&M);
}

