#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAXPIPE 4096

int main ()  {
	int fd;
	char buffW[] = "Hello", buffR[MAXPIPE];
	char fifoName[] =  "fifo.1";

 	unlink(fifoName); 
	if(mkfifo(fifoName, 0666) == -1) {
		perror("fifo ");
		exit(-1);
	}
	fd = open(fifoName, 0666);
	if(fd == -1) {
		perror("open fifo ");
		exit(-1);
	}
	write(fd, buffW, strlen(buffW));

	if(read(fd, &buffR, sizeof(buffR)) == -1) {
		perror("read fifo ");
		exit(-1);	
	}
	printf("%s\n", buffR);

	exit(0);
}