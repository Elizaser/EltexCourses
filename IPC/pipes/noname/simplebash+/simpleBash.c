#include "simpleBash.h"

#define PIPE 4096
#define MAXLINE 100

void runSB() {
	char *strIn = (char*)malloc(MAXLINE * sizeof(char));

	while(1) {
		getComands(strIn);
		if(callComands(strIn) == -1) break;
	}

	free(strIn);
}

void getComands(char* strIn) {
	printf("\nin: ");
	fgets(strIn, MAXLINE, stdin);
	strIn[strlen(strIn) - 1] = 0;
}

int callComands(char* strIn) {
	int countProcesses = 0, countArgs = 0;
	int fdNew[2], fdOld[2];
	char **args = NULL;
	char **processes = NULL;
	char *buff = (char*)malloc(PIPE * sizeof(char));

	countProcesses = pars(strIn, &processes, "|");
	if(countProcesses == 0) return 0;
	if(strcmp(processes[0], "exit") == 0)  return -1;
	
	// for (int i = 0; i < countProcesses; ++i) printf("processes = %s\n", processes[i]);

	for(int i = 0; i < countProcesses; i++) {
		countArgs = pars(processes[i], &args, " ");

		for(int j = 0; j < 2; j++) {
			fdOld[j] = fdNew[j];
		}
		if(pipe(fdNew) < 0) {
			perror("pipe1: ");
			exit(-1);
		}
		callComand(fdNew, fdOld, args);		
	}
	close (fdNew[1]);
	read(fdNew[0], buff, PIPE);
	printf("In canal:\n%s", buff);

	for(int i = 0; i < countProcesses; i++) free(processes[i]);
	for(int i = 0; i < countArgs; i++) free(args[i]);
	free(args);
	free(processes);
	free(buff);

	return 0;
}
int callComand(int fdNew[], int fdOld[], char **args) {
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) {
		close(fdNew[0]);
		close(fdOld[1]);
		dup2(fdNew[1], 1);
		dup2(fdOld[0], 0);

		if(execvp(args[0], args) == -1) {
			perror("execl");
			exit(-1);
		} 
	} else {
		wait(&status);
	
		if(WEXITSTATUS(status) != 0) {
			perror("Ошибкa: ");
			return -1;
		}
	} 

	return 0;
}