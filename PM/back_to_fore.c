#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("process is running in the background");
	fflush(stdout);
	while(1);
}
