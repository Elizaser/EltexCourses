#include "parsString.h"
int getCountWords(char * strArgs) {
	int countWords = 0;

	for (int i = 0; strArgs[i + 1] != '\n'; i++) {
			if(strArgs[i] == ' ' && strArgs[i + 1] != ' ')
				countWords++;
	}
	if(strArgs[0] != ' ')
		countWords++;	
	return countWords;
}

void stringInArray(char *string, char **array, int count) {
	for(int i = 0, k = 0; i < count; i++, k++) {
			for (int j = 0; string[k] != ' ' && string[k] != '\n'; j++, k++) { 
				array[i][j] = string[k];
			}
		}		
	array[count] = NULL;
}