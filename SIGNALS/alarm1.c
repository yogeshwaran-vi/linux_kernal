#include<stdio.h>
#include<unistd.h>
 int main()
 {  
    printf("hello..\n");
    alarm(10);
    alarm(5);
    alarm(1);
    printf("hi..\n");
    while(1);
}
