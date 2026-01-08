#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <fcntl.h>
#define MSG_EXCEPT 020000
struct msg
{
	long mtype;
	char mtext[100];
};
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("usage: <m.type>");
		return 0;
	}
	int id;
	id=msgget(6,IPC_CREAT|0664);
	printf("msg id=%d\n",id);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	struct msg v;
	int ret;
	int mtype=atoi(argv[1]);
	msgrcv(id,&v,sizeof(v.mtext),mtype,0);
	printf("mtype:%ld mtext:%s\n",v.mtype,v.mtext);
}
