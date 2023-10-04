#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <time.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

void  main(void)
{
  pid_t  pid, mypid;
  int    i;
  char   buf[BUF_SIZE];

  for (i = 1; i <= MAX_COUNT; i++) {
    mypid = fork();
    pid = getpid();

    if(mypid == 0){
      switch(i){
        case 1:
          printf("Do something P%d\n", i);
          break;
        case 2:
          printf("Sleep 5 seconds %d\n", i);
          sleep(5);
          break;
        default:
          printf("everybody else %d\n", i);
          break;
      }
    }
    else if (mypid < 0){
      printf("Error can't fork \n");
    }

    sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
    write(1, buf, strlen(buf));

    sleep(5);
  } 
}
