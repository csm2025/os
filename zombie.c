#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid > 0)
    {
        // This is the parent process
        printf("Parent process (PID %d) sleeping for a while...\n", getpid());
        sleep(5);
        printf("Parent process exiting.\n");
    }
    else
    {
        // This is the child process
        printf("Child process (PID %d) exiting immediately.\n", getpid());
        exit(EXIT_SUCCESS);
    }

    // The parent process waits for the child to exit
    int status;
    pid_t terminated_pid = waitpid(child_pid, &status, 0);

    if (terminated_pid == -1)
    {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status))
    {
        printf("Child process (PID %d) exited with status %d.\n", terminated_pid, WEXITSTATUS(status));
    }
    else
    {
        printf("Child process did not exit normally.\n");
    }

    return 0;
}
