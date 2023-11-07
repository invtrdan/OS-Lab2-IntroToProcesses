#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h> // For wait()
#include <stdlib.h>   // For exit()
#include <unistd.h>   // For fork(), getpid()

#define MAX_COUNT 200

void ChildProcess(void);  /* child process prototype  */
void ParentProcess(void); /* parent process prototype */

int main(void) // main should return an int
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        ChildProcess();
        // We must exit in child process to prevent it from continuing
        // with the rest of the main function.
        exit(EXIT_SUCCESS);
    }
    else
    {
        ParentProcess();
        wait(&status); // wait for the child process to complete

        if (WIFEXITED(status)) // Check if child terminated normally
        {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    }

    return 0; // Return success code
}

void ChildProcess(void)
{
    int i;

    for (i = 1; i <= MAX_COUNT; i++)
        printf("   This line is from child, value = %d\n", i);
    printf("   *** Child process is done ***\n");

    exit(10); // Child process returns 10 as exit status
}

void ParentProcess(void)
{
    int i;

    for (i = 1; i <= MAX_COUNT; i++)
        printf("This line is from parent, value = %d\n", i);
    printf("*** Parent is done ***\n");
}
