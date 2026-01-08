#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
int main()
{
	struct rlimit v;
	getrlimit(RLIMIT_FSIZE,&v);
	printf("soft=%lu\n",v.rlim_cur);//soft limit
	printf("hard=%lu\n",v.rlim_max);//hard limit
	v.rlim_cur=26;
	setrlimit(RLIMIT_FSIZE,&v);
	getrlimit(RLIMIT_FSIZE,&v);
	printf("soft=%lu\n",v.rlim_cur);//soft limit
	printf("hard=%lu\n",v.rlim_max);//hard limit
	char a[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	FILE *fp=fopen("temp","w");
        fprintf(fp,"%s",a);	
}
