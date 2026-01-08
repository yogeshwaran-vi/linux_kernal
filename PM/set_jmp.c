#include<stdio.h>
#include<unistd.h>
#include<setjmp.h>
jmp_buf var;
int main()
{
     int r;
     printf("Hello\n");
     r = setjmp(var);
     printf("r = %d\n",r);
     printf("after setjmp()...\n");
     printf("longjmp() going to be called\n");
     sleep(2);
     longjmp(var,5);
     printf("after longjmp()...\n");
}
