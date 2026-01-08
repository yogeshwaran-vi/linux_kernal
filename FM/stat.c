#include <stdio.h>
#include <sys/stat.h>
int main(int argc,char**argv)
{
	struct stat v;
	if(argc!=2)
	{
		perror("invalid command");
		return 0;
	}

	if((lstat(argv[1],&v))<0)
	{
		perror("stat");
		return 0;
	}

	printf("stat_ino=%ld\t",v.st_ino);
	printf("stat_mode=%o\n",v.st_mode);
	printf("stat_nlink=%ld\t",v.st_nlink);
	printf("stat_size=%ld\n",v.st_size);
}
