#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <dlfcn.h>
#include <string.h>
#define sizeNameMenuItem 20 
void** LoadingLibraries(int argc, char* argv[], int *numberMenuItem);
char** MenuFormation(void **fdLibrary, int numberMenuItem);
void PrintMenu(char **menu, int numberMenuItem);