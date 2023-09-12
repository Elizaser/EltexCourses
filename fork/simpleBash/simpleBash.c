#include "simpleBash.h"
void runSB() {
	char **args = NULL;
	int countArgs = 0;
	
	while(1) {
		countArgs = inputComand(&args);
		if(strcmp(args[0], "exit") == 0)  break;
		callComand(args, countArgs);		
	}

	for(int i = 0; i < countArgs; i++){
		free(args[i]);
	}
	free(args);
}
int inputComand(char*** args) {
	char strArgs[sizeInBuffer];
	int countArgs;

	printf("\nin: ");
	fgets(&strArgs, sizeInBuffer, stdin);
	
	countArgs = getCountWords(strArgs);

	*args = realloc(*args, (countArgs + 1) * sizeof (*args));
	for(int  i = 0; i < countArgs + 1; i++) {
		(*args)[i] = realloc((*args)[i], sizeInBuffer * sizeof(**args));
		memset((*args)[i],0,sizeof((*args)[i]));
	}

	stringInArray(strArgs, *args, countArgs);
	return countArgs;
}
void callComand(char **args, int count) {
	pid_t pid;
	int status;

	printf("count  = %d\n", count);
	for(int  i = 0; i < count; i++) {
		printf("%s+\n", args[i]);
	}

	pid = fork();
	if (pid == 0) {
		if(execvp(args[0], args) == -1) {
			perror("execl");
			exit(-1);
		} 
		exit(0);
	} else {
		wait(&status);
		if(WEXITSTATUS(status) != 0) {
			printf("Ошибкa\n");
		}
	} 
}