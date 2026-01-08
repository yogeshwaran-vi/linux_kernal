#include<stdio.h>
int fact(int,int);
int main()
{
        int n;
        printf("Enter the n value\n");
        scanf("%d",&n);
        int f = fact(n,1);
        printf("factorial f = %d\n",f);
}
int fact(int num,int f)
{
        if(num != 0)
        {
                f = f*num--;
                return fact(num,f);
        }
        else
        return f;
}
