/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handled = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  handled = 1; //
  // exit(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  // while(1); //busy wait for signal to be delivered
  // return 0; //never reached
  // while (!handled);
  // printf("Turing was right!\n"); // Print the additional message
  while (1)
  {
    while (!handled); // Wait for the signal to be delivered and handled
    printf("Turing was right!\n"); 
    handled = 0; // Reset the handled flag
    alarm(1); // Schedule the next SIGALRM for 1 second
  }
  return 0;
}
