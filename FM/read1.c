#include<stdio.h>
 #include<unistd.h>
 #include<string.h>
 #include<fcntl.h>
 int main()
 {
        struct st
        {
                char ch;
                 int x;
                float f;
                char s[20];
        }v;
        int fd = open("new.txt",O_RDONLY);
        if(fd < 0) {
        perror("open");
        return 0;
         }
        read(fd,&v,sizeof(v));
        printf("ch = %c  x = %d  f = %f  s = %s\n",v.ch,v.x,v.f,v.s);
}
