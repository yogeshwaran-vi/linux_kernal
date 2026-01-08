#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./a.out <dir_name>\n");
		return 0;
	}

	DIR *ds=opendir(argv[1]);

	if(ds==NULL)
		printf("Directory not exists\n");
	else
		printf("Directory exists\n");
}
