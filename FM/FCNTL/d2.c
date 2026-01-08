 #include<stdio.h>
 #include<unistd.h>
 #include<fcntl.h>
 int main()
 {
         char s[20]="123456789";
         int fd,i = 0;
         fd = open("temp1.txt", O_WRONLY|O_CREAT|O_APPEND,0664);
         if(fd < 0) {
         perror("open");
         return 0;
         }
        printf("writing into file\n");
        while(s[i])
        {
           write(fd,s+i,1);
           i++;
           sleep(1);
        }
        printf("writing completed..\n");
  }
