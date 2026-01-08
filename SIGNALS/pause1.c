#include<stdio.h>
 #include<signal.h>
 #include<unistd.h>
 void isr(int n)
 {
         printf("In isr()...\n");
 }
 int main()
 {
         signal(3,isr);
         printf("pid : %d\n",getpid());
         printf("process is paused...\n");
         int ret = pause();
         printf("after pause(), ret = %d\n",ret);
         printf("bye..\n");
 }
