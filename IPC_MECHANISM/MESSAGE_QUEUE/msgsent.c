#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/msg.h>
struct msg
{
	long mtype;
	char mtext[20];
};
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("usage:./msg_sent mtype mtext");
		return 0;
	}
	int id,ret;
	id=msgget(6,IPC_CREAT|0664);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	printf("msgget=%d\n",id);
	struct msg v;
	v.mtype=atoi(argv[1]);
	strcpy(v.mtext,argv[2]);
	ret=msgsnd(id,&v,strlen(v.mtext)+1,1);
	printf("ret=%d\n",ret);
}
