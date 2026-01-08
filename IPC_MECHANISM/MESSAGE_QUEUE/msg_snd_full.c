#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/msg.h>
struct msg
{
	long mtype;
	char mtext[20];
};
int main()
{
	int id;
	id=msgget(10,IPC_CREAT|0664);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	struct msg v;
	if(fork()==0)
	{
		while(1)
		{
			v.mtype=1;
			printf("snd:");
			scanf("%s",v.mtext);
			msgsnd(id,&v,strlen(v.mtext)+1,0);
		}
	}
	else
	{
		while(1)
		{
			msgrcv(id,&v,sizeof(v.mtext),2,0);
			printf("rcv:%s\n",v.mtext);
		}
	}
}
