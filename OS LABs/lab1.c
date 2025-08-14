#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#ifdef __unix__
#include <sys/wait.h>
#endif

int main()
{
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }
    if (pid1 == 0)
    {
        printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(0);
    }
    else
    {
        pid2 = fork();
        if (pid2 < 0) {
            perror("fork failed");
            exit(1);
        }
        if (pid2 == 0)
        {
            printf("Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
            exit(0);
        }
        else
        {
#ifdef __unix__
            // Wait for both children to finish (UNIX)
            wait(NULL);
            wait(NULL);
#endif
            printf("Parent: PID = %d\n", getpid());
        }
    }
    return 0;
}