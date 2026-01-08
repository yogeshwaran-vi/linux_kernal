#include<stdio.h>
 #include<unistd.h>
 #include<signal.h>
 void isr(int n)
 {
         printf("In Isr(), n = %d\n",n);
         printf("SIGALAM signal is received...\n");
 }
 int main()
 {
         signal(SIGALRM,isr);
         alarm(10);
         printf("alarm() is set for 10 seconds\n");
         printf("Process is in infinite loop...\n");
         while(1);
 }
