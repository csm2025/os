#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t childpid;
    int retval, status;
    childpid = fork();
    if (childpid >= 0)
    {
        if (childpid == 0)
        {
            printf("child:Iam the Child process\n");
            printf("child:Here's my PID:%d\n", getpid());
            printf("child:My parent's pid is %d\n", getppid());
            printf("child:The value of my copy of childpid is %d\n", childpid);
            printf("child:sleeping for 10 seconds\n");
            sleep(10);
            printf("child:Enter an exit value");
            scanf("%d", &retval);
            printf("child:Goodbye!\n");
            exit(retval);
        }
        else
        {
            printf("parent:Iam the parent process\n");
            printf("parent:Here's my PID:%d\n", getpid());
            printf("parent:The value of my copy of childpid is %d\n", childpid);
            printf("parent:I will now wait for my child process to exit\n");
            wait(&status);
            if (WIFEXITED(status))
                printf("Parent: child has exited with status %d.\n", WEXITSTATUS(status));
            printf("\nparent:Goodbye!\n");
            exit(0);
        }
    }
    else
    {
        perror("fork");
        exit(0);
    }
}