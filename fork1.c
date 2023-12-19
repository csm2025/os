#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
// #include <unistd.h>

int globalvariable = 2;
int main()
{
	int localvar = 20;
	int i = 1;
	int pID = fork();
	if (pID == 0)
	{
		printf("In Child Process");
		globalvariable++;
		localvar++;
	}
	else if (pID < 0)
	{
		printf("Failed to fork");
		exit(1);
	}
	else
	{
		printf("Parent Process");
	}
	printf("Global Variable: %d", globalvariable);
	printf("Stack Variable: %d", localvar);
	return 0;
}
