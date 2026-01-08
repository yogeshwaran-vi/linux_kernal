#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
int main()
{
    struct rlimit v;
    getrlimit(RLIMIT_CORE,&v);

    printf("soft = %u\n",(unsigned)v.rlim_cur);
    printf("hard = %u\n",(unsigned)v.rlim_max);

    v.rlim_cur = 1000; //soft limit

    setrlimit(RLIMIT_CORE,&v);
    getrlimit(RLIMIT_CORE,&v);
    printf("soft = %u\n",(unsigned)v.rlim_cur);
}
