#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("New process replaced on the current process...\n");
	printf("In new process(./p1)\n");
	printf("Hello...\n");
	write(3,"Chennai\n",8);
	printf("New process terminated...\n");
}
