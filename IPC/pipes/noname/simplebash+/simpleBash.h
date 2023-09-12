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
int getJob(char* strIn, char*** array, char* tok);
void callComands(int fdR[], int fdW[], char **args, int count);

#endif /*SIMPLEBASH_H*/