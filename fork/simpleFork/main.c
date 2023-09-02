#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main (void) {
	pid_t childPid;
	int status;

	childPid = fork();
	if(childPid == 0) {
		printf("Child pid = %d\n", getpid());
		exit(15);
	} else {
		printf("Parent pid = %d\n", getpid());
		wait(&status);
		printf("status = %d\n", WEXITSTATUS(status));
	}

	exit(0);
}