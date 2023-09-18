#include "parsString.h"
#include <stdlib.h>
int pars(char* string, char ***array, char* tok) {
	int count;
	
	count = getCount(string, tok);
	*array = realloc(*array, (count + 1) * sizeof(*array));
	for(int i = 0; i < count; ++i) {
		(*array)[i] = realloc((*array)[i], 20 * sizeof(**array));
		// memset((*array)[i],0,sizeof((*array)[i]));
	}
	stringInArray(string, *array, tok);
	return count;
}

int getCount(char * string, char *tok) {
	int countWords = 0;
	char *tStrArgs = malloc((strlen(string)) * sizeof (*tStrArgs));
	strcpy(tStrArgs, string);
	tStrArgs = strtok(tStrArgs, tok);

	while(tStrArgs != NULL) {
		countWords++;
		tStrArgs = strtok(NULL, tok);
	}

	free(tStrArgs);
	return countWords;
}

void stringInArray(char *string, char **array, char *tok) {
	int i = 0;
	char *tStrArgs = malloc((strlen(string)) * sizeof (*tStrArgs));
	strcpy(tStrArgs, string);
	tStrArgs = strtok(tStrArgs, tok);

	while(tStrArgs != NULL) {
		strcpy(array[i], tStrArgs);
		tStrArgs = strtok(NULL, tok);
		i++;
	}
	array[i] = NULL;
	free(tStrArgs);
}