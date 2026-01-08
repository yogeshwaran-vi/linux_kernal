#include<stdio.h>
#include<unistd.h>
  int main()
  {
      int ret;
      printf("alarm() return values...\n");
      ret = alarm(10);
      printf("1) ret = %d\n",ret);
     // sleep(3);
 
      ret = alarm(5);
      printf("2) ret = %d\n",ret);
      //sleep(2);
 
      ret = alarm(10);
      printf("3) ret = %d\n",ret);
  }
