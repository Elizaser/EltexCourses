#include "parsString.h"
int getCount(char * strArgs, char *tok) {
	int countWords = 0;
	char *tStrArgs = malloc((strlen(strArgs)) * sizeof (*tStrArgs));
	strcpy(tStrArgs, strArgs);
	tStrArgs = strtok(tStrArgs, tok);

	while(tStrArgs != NULL) {
		countWords++;
		tStrArgs = strtok(NULL, tok);
	}

	free(tStrArgs);
	return countWords;
}

void stringInArray(char *string, char **array, int count, char *tok) {
	int i = 0;
	char *tStrArgs = malloc((strlen(string)) * sizeof (*tStrArgs));
	
	strcpy(tStrArgs, string);
	tStrArgs = strtok(tStrArgs, tok);

	while(tStrArgs != NULL) {
		strcpy(array[i], tStrArgs);
		tStrArgs = strtok(NULL, tok);
		i++;
	}
	array[count] = NULL;
	free(tStrArgs);
}

// void getProcess(char *string, char **process, int count) {
// 	int i = 0;
// 	char *tStrArgs = malloc((strlen(string)) * sizeof (*tStrArgs));
	
// 	strcpy(tStrArgs, string);
// 	tStrArgs = strtok(tStrArgs, "|");

// 	while(tStrArgs != NULL) {
// 		strcpy(array[i], tStrArgs);
// 		tStrArgs = strtok(NULL, "|");
// 		i++;
// 	}
// 	array[count] = NULL;
// 	free(tStrArgs);
// }