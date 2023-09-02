#include "fInOut.h"
int writeToFile(char file[], char buffW[], int size) {
	
	int fd;	

	fd  = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("Error: not open file\n");
		return -1;
	}
	if(write(fd, buffW, size) != size) {
		printf("Error: not write in file\n");
		return -1;
	}
	if(close(fd) != 0) {
		printf("Error: not close file\n");
		return -1;	
	}
	return 0;
}

int readFile(char file[], char buffR[], int size) {
	int fd;
	
	fd = open(file, O_RDONLY, S_IRUSR);
	if (fd < 0) {
		printf("Error: not open file\n");
		return -1;
	}
	if(read(fd, buffR, size) != size) {
		printf("Error: not read file\n");
		return -1;	
	}
	if(close(fd) != 0) {
		printf("Error: not close file\n");
		return -1;	
	}
	return 0;
}