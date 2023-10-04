#include  <stdio.h>
#include  <sys/types.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
  pid_t  pid;
  int status;

  pid = fork();
  if (pid == 0) 
    ChildProcess();
  else 
    ParentProcess();
}

void  ChildProcess(void)
{
  int   i;

  for (i = 1; i <= MAX_COUNT; i++)
    printf("   This line is from child, value = %d\n", i);
  printf("   *** Child process is done ***\n");

  exit(10);
}

void  ParentProcess(void)
{
     int   i;
     int status;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");

     wait(&status); // wait for the child process to complete
}
