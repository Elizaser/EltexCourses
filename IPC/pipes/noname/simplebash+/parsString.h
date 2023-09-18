#ifndef PARSSTRING_H
#define PARSSTRING_H

#include <string.h>

int pars(char* string, char ***array, char* tok);
int getCount(char * string, char* tok);
void stringInArray(char *string, char **array,  char *tok);

#endif /*PARSSTRING_H*/