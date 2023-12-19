// #include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
// #include<unistd.h>
#include <stdio.h>
int main()
{

    int childpid;
    childpid = fork();
    if (childpid < 0)
    {
        printf("Fork Failed");
        exit(-1);
    }
    else if (childpid == 0)
    {
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child Complete");
        exit(0);
    }
}