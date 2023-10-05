/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handled = 0;
int alarm_count = 0;

void alarm_handler(int signum)
{
  alarm_count++;
}

void ctrlc_handler(int signum)
{
  printf("\nTotal alarms: %d\n", alarm_count);
  printf("Total execution time: %d seconds\n", alarm_count);
  exit(0);
}

// void handler(int signum)
// { //signal handler
//   printf("Hello World!\n");
//   handled = 1; //
//   // exit(1); //exit after printing
// }

int main(int argc, char * argv[])
{
  signal(SIGALRM, alarm_handler); //register handler to handle SIGALRM
  signal(SIGINT, ctrlc_handler);
  alarm(1); //Schedule a SIGALRM for 1 second
  // while(1); //busy wait for signal to be delivered
  // return 0; //never reached
  // while (!handled);
  // printf("Turing was right!\n"); // Print the additional message
  while (1)
  {
    // while (!handled); // Wait for the signal to be delivered and handled
    // printf("Turing was right!\n"); 
    // handled = 0; // Reset the handled flag
    // alarm(1); // Schedule the next SIGALRM for 1 second
  }
  return 0;
}
