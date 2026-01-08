#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main()
 {
        printf("pid : %d\n",getpid());
        printf("process is paused...\n");
        pause();  // process suspended untill signal raised 
        printf("bye..\n");
 }
