#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void*thread1(void *);
void*thread2(void *);
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	printf("in main()...thread id1 = %lu\n",t1);
	printf("in main()...thread id2 = %lu\n",t2);
	sleep(3);
	printf("in main()...exit\n");
}
void *thread1(void *p)
{
	size_t id=pthread_self();
	printf("thread id1 = %lu\n",id);
	sleep(1);
	printf("thread-1 exit\n");
}
void *thread2(void *p)
{
	size_t id=pthread_self();
	printf("thread id2 = %lu\n",id);
	sleep(2);
	printf("thread-2 exit\n");
}
