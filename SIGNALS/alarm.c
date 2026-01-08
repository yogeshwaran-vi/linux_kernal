#include<stdio.h>
#include<unistd.h>
 int main()
 {
    printf("hello..\n");
    alarm(10);
    printf("hi..\n");
    while(1);
 }
