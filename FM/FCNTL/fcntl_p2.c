//p2 process of fcntl record locking
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	char s[]="123456789";
	int i=0,fd=open("new.txt",O_WRONLY|O_CREAT|O_APPEND,0664);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	struct flock v;
	v.l_type   = F_WRLCK;
	v.l_whence = SEEK_SET;
	v.l_start  = 0;
	v.l_len    = 0;
	printf("starting write into a file\n");
	fcntl(fd,F_SETLKW,&v);
	while(s[i])
	{
		write(fd,s+i,1);
		sleep(1);
		i++;
	}
	printf("writing completed...\n");
	fcntl(fd,F_UNLCK,&v);
}
