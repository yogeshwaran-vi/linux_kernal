#include<stdio.h>
#include<signal.h>
 void isr(int n)
 { 
      printf("in isr..\n");
 }
 int main()
 {  
    signal(2,SIG_IGN);

    struct sigaction v1,v2;
    
    v1.sa_handler = isr;
    sigemptyset(&v1.sa_mask);
    v1.sa_flags = 0;
 
    sigaction(2,&v1,&v2);
    printf("Old action is : ");
         if(v2.sa_handler == SIG_DFL)
         printf("default..\n");
         else if(v2.sa_handler == SIG_IGN)
         printf("Ignore..\n");
         else
         printf("isr..\n");

         printf("Infinite process...\n");
         while(1);
 } 
