#include<stdio.h>
#include<string.h>
//#include<strings.h>
int main()
{
         int a[10];
         //bzero(a,sizeof a);
         memset(a,1,sizeof a);
         for(int i = 0;i<10;i++)
         printf("%d ",a[i]);
         printf("\n");
}
