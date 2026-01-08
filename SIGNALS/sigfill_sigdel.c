#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void isr(int n)
{
        printf("In isr()...\n");
        sleep(30);
        printf("isr() is exit\n");
}
int main()
{
        struct sigaction v;
        v.sa_handler = isr;
        sigfillset(&v.sa_mask);
        sigdelset(&v.sa_mask,3);
        sigdelset(&v.sa_mask,11);
        v.sa_flags = 0;
        sigaction(2,&v,0);
        printf("Infinite process..., pid : %d\n",getpid());
        while(1); 
}
