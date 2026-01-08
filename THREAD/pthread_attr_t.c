#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void*thread(void *);
int main()
{
	size_t stack;
	pthread_t t1;
	pthread_attr_t v;
	pthread_attr_init(&v);
	pthread_attr_getstacksize(&v,&stack);
	printf("stack size = %lu\n",stack);
	stack=stack-100000000;
	pthread_attr_setstacksize(&v,stack);
	printf("after modify stack size = %lu\n",stack);
	pthread_create(&t1,&v,thread,0);
	printf("thread id = %lu\n",t1);
	printf("in main()....infinte loop\n");
	while(1);
}
void *thread(void *p)
{
	printf("in thread process...\n");
	sleep(5);
	printf("thread exit\n");
}
