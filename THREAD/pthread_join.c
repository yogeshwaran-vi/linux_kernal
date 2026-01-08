#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void*thread1(void *);
void*thread2(void *);
int main()
{
	char*ptr1,*ptr2;
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	printf("in main()...thread id1 = %lu\n",t1);
	printf("in main()...thread id2 = %lu\n",t2);
	pthread_join(t1,(void**)&ptr1);
	pthread_join(t2,(void**)&ptr2);
	printf("in main()...ptr1=%s\n",ptr1);
	printf("in main()...ptr2=%s\n",ptr2);
}
void *thread1(void *p)
{
	printf("thread id1 delay 3\n");
	sleep(3);
	printf("thread-1 exit\n");
	pthread_exit("bye bye thread1");
}
void *thread2(void *p)
{
	printf("thread id2 delay 5\n");
	sleep(5);
	printf("thread-2 exit\n");
	pthread_exit("bye bye thread2");
}
