#ifndef SIMPLEBASH_H
#define SIMPLEBASH_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "parsString.h"

#define sizeInBuffer 50

void runSB();
void getComands(char* strIn);
int callComands(char* strIn);
int callComand(int fdR[], int fdW[], char **args);

#endif /*SIMPLEBASH_H*/