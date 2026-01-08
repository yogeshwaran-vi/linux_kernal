#include<stdio.h>
 #include<unistd.h>
 #include<signal.h>
 int time = 5;
 void isr(int n)
 {
         alarm(--time);
         printf("alarm() is reset for %d seconds\n",time);
          if(time == 0)
         raise(9);
 }
 int main()
 {
         signal(SIGALRM,isr);
         alarm(time);
         printf("alarm() is set for %d seconds\n",time);
         printf("Process is in infinite loop...\n");
         while(1);
 }
