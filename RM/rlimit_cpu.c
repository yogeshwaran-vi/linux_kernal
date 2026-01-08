#include<stdio.h>
#include<sys/resource.h>
main()
{
    struct rlimit v;
    getrlimit(RLIMIT_CPU,&v);
    printf("soft=%lu\n", v.rlim_cur);
    printf("hard=%lu\n",v.rlim_max);
    v.rlim_cur=99999999999999;
       setrlimit(RLIMIT_CPU,&v);
       getrlimit(RLIMIT_CPU,&v);
   printf("soft=%lu\n",v.rlim_cur);
   printf("Infinite process...\n");
   while(1);
}  
