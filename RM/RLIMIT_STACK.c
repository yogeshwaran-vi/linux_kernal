#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
int main()
{
	struct rlimit v;
	getrlimit(RLIMIT_STACK,&v);
	printf("soft=%lu\n",v.rlim_cur);//soft limit
	printf("hard=%lu\n",v.rlim_max);//hard limit
	v.rlim_cur=20000;
	setrlimit(RLIMIT_STACK,&v);
	getrlimit(RLIMIT_STACK,&v);
	printf("soft=%lu\n",v.rlim_cur);//soft limit
	printf("hard=%lu\n",v.rlim_max);//hard limit
	system("./fact");

}
