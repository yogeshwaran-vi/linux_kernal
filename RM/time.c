#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<time.h>
int main()
  {
      time_t t;
          while(1)
          {
                time(&t);
                printf("%lu\n",t);
                printf("%s\n",ctime(&t));
                sleep(1);
                system("clear");
         }
   }
