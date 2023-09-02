#include "fInOut.h"

#define BUFFER_SIZE 64

int main (void) {
	char file[] = "test.txt";
	char buffW[] = "I am writing in file! And i am read file, you look!";
	char buffR[BUFFER_SIZE];

	if(writeToFile(file, buffW, sizeof(buffW)) == -1) exit(-1);	
	readFile(file, buffR, sizeof(buffW));
	printf("%s\n", buffR);
	
	exit(0);
}