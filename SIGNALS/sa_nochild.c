#include<stdio.h>
 #include<unistd.h>
 #include<signal.h>
 void isr(int n) {
 printf("in isr..\n");
 }
 int main()
 {
    if(fork()==0)
    {
         printf("in child pid = %d\n",getpid());
         sleep(30);
         printf("child exit..\n");
    }
    else
    {
         struct sigaction v;
         v.sa_handler = isr;
         sigemptyset(&v.sa_mask);
         //v.sa_flags = 0;
         v.sa_flags = SA_NOCLDSTOP|SA_NOCLDWAIT;
         sigaction(17,&v,0);
         while(1);
    }
  }
