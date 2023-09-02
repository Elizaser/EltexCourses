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
int inputComand(char ***args);
void callComand(char **args, int count);

#endif /*SIMPLEBASH_H*/