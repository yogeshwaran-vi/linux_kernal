#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int g=0;
void*thread1(void *);
void*thread2(void *);
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	sleep(3);
	printf("in main()...exit\n");
}
void*thread1(void *p)
{
	g++;
	printf("in thread1 g = %d\n",g);
	sleep(2);
	printf("after change g value : g = %d\n",g);
}
void*thread2(void *p)
{
	printf("in thread2 g = %d\n",g);
	g=10;
	sleep(1);
	g++;
	printf("after change g value : g = %d\n",g);
}

