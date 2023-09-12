#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 4096

int main(void) {
	pid_t p;
	int fd1[2], fd2[2];
	char buffW1[] = "Hello", buffR1[MAX];
	char buffW2[] = "Hi", buffR2[MAX];
	int status;

	if(pipe(fd1) < 0) {
		perror("pipe1: ");
		exit(-1);
	}
	if(pipe(fd2) < 0) {
		perror("pipe2: ");
		exit(-1);
	} 

	p = fork();
	if(p == 0) {
		close(fd1[1]);
		read(fd1[0], buffR1, MAX);
		printf("Parent: %s\n", buffR1);

		close(fd2[0]);
		if(write(fd2[1], buffW2, sizeof(buffW2)) != sizeof(buffW2)) {
			perror("write: ");
			exit(-1);
		}

		exit(0);
	}

	close(fd1[0]);
	if(write(fd1[1], buffW1, sizeof(buffW1)) != sizeof(buffW1)) {
		perror("write: ");
		exit(-1);
	}

	close(fd2[1]);
	read(fd2[0], buffR2, MAX);
	printf("Children: %s\n", buffR2);

	wait(&status);

	exit(0);
}