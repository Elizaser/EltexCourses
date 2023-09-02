#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int writeToFile(char file[], char buffW[], int size);
int readFile(char file[], char buffR[], int size);