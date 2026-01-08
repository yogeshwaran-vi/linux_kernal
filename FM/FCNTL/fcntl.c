//record locking p1
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char s[20]="abcdefghijk";
	int fd,i = 0;
	fd = open("new.txt", O_WRONLY|O_CREAT|O_APPEND,0664);
	if(fd < 0) 
	{
		perror("open");
		return 0;
	}
	struct flock v;
	v.l_type = F_WRLCK;
	v.l_whence = SEEK_SET;
	v.l_start = 0;
	v.l_len = 0;
	printf("The process about to write the data into a file\n");
	fcntl(fd,F_SETLKW,&v);
	printf("writing into file\n");
        while(s[i])
        {
           write(fd,s+i,1);
           i++;
           sleep(1);
        }
        printf("writing completed..\n");
        fcntl(fd,F_UNLCK,&v);
}
