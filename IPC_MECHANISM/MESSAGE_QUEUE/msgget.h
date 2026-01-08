#include <stdio.h>
#include <sys/msg.h>
int main()
{
	int id;
	id=msgget(4,IPC_CREAT|0664);

	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	printf("msg id= %d\n",id);
}
