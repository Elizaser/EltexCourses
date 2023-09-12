#include "simpleBash.h"
#define MAX 4096
void runSB() {
	char strIn[sizeInBuffer] = "ps -A | head -5" ;
	char **args = NULL;
	char **processes = NULL;
	int countArgs = 0, countProcesses = 0;
	int fdW[2], fdR[2];
	// int fdIn = stdin, fdOut = stdout;	
	char buffR[MAX];
	// char buffR2[MAX];


	while(1) {
		
		printf("\nin: ");
		fgets(&strIn, sizeInBuffer, stdin);
		strIn[strlen(strIn) - 1] = 0;
		
		countProcesses = getJob(strIn, &processes, "|");
		if(strcmp(processes[0], "exit") == 0)  break;
		for(int i = 0; i < countProcesses; i++){
			printf("Process: %s\n", processes[i]);
		}


		if(countProcesses > 1) { //  ps -A | head -5
			for(int i = 0; i < countProcesses; i++) {
				countArgs = getJob(processes[i], &args, " ");
				for(int i = 0; i < countArgs; i++) {
					printf("arg: %s\n", args[i]);
				}

				// printf("wesdf1\n");
			
				if(pipe(fdW) < 0) {
					perror("pipe1: ");
					exit(-1);
				}
				callComands(fdR, fdW, args, countArgs);		
				// printf("wesdf2\n");
				if(pipe(fdR) < 0) {
				perror("pipe: ");
				exit(-1);
				}
			
				// close(fdR[0]);
				// close(fdW[1]);
				read(fdW[0], buffR, MAX);
				// printf("In canal fdW: %srr\n", buffR);		
				// *fdW = NULL;
				// *fdR = NULL;
				if(write(fdR[1], buffR, sizeof(buffR)) != sizeof(buffR)) {
					perror("write: ");
					exit(-1);
				}	
				// read(fdR[0], buffR, MAX);
				// printf("In canal fdR: %s rrr\n", buffR);

			}

			read(fdR[0], buffR, MAX);
			printf("END In canal:\n %s\n", buffR);
			continue;
		}

		countArgs = getJob(processes[0], &args, " ");
		for(int i = 0; i < countArgs; i++) {
			printf("arg: %s\n", args[i]);
		}
		callComands(fdR, fdW, args, countArgs);
				 
				// sleep(2);
	}

	for(int i = 0; i < countProcesses; i++){
		free(processes[i]);
	}
	free(processes);
	for(int i = 0; i < countArgs; i++){
		free(args[i]);
	}
	free(args);
}
int getJob(char* strIn, char*** array, char* tok) {
	int count;
	
	count = getCount(strIn, tok);

	*array = realloc(*array, (count + 1) * sizeof (*array));
	for(int  i = 0; i < count + 1; i++) {
		(*array)[i] = realloc((*array)[i], sizeInBuffer * sizeof(**array));
		memset((*array)[i],0,sizeof((*array)[i]));
	}

	stringInArray(strIn, *array, count, tok);
	
	return count;
}


void callComands(int fdR[], int fdW[], char **args, int count) {
	pid_t pid;
	int status;
	char buffR[MAX];

	pid = fork();
	if (pid == 0) {
		close(fdR[1]);
		close(fdW[0]);
		dup2(fdR[0], 1);
		dup2(fdW[1], 0);
		// perror("Children\n");
		// read(fdR[0], buffR, MAX);
		// printf("In canal fdR: %s rrr\n", buffR);

		if(execvp(args[0], args) == -1) {
			perror("execl");
			exit(-1);
		} 
		exit(0);
	} else {
		wait(&status);
		// printf("Parent\n");

		// read(fdW[0], buffR, MAX);
		// printf("In canal fdW: %s rrr\n", buffR);		
		// if(write(fdR[1], buffR, sizeof(buffR)) != sizeof(buffR)) {
		// 	perror("write: ");
		// 	exit(-1);
		// }
		
		if(WEXITSTATUS(status) != 0) {
			perror("Ошибкa: ");
		}
	} 
}