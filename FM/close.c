#include<stdio.h>
#include<unistd.h>
int main()
{
   int i=0,a;
   while(1)
     {
      	printf("hello..\n");
      	scanf("%d",&a);
        i++;
        if(i==3)
	{
       		close(0); 
		close(1);
	}
     }
}
