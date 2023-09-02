#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Выстроить иерархию процессов вида:
//     1
//    / \
//   2   3
//  / \  | 
// 4   5 6

int main (void) {

	pid_t p2, p3, p4, p5, p6;
	int status;

	p2 = fork();
	p3 = fork();
	if(p2 > 0 && p3 > 0) { // 1
		// printf("p1 pid = %d\n", getpid());
		// printf("p1 ppid = %d\n", getppid());
		wait(&status);
		wait(&status);
		exit(0);
	}
	if(p2 == 0 && p3 == 0){ //4
		// printf("p4 pid = %d\n", getpid());
		// printf("p4 ppid = %d\n", getppid());
		exit(4);
	}
	p4 = fork();

	if(p2 > 0 && p4 > 0){ //3
		// printf("p3 pid = %d\n", getpid());
		// printf("p3 ppid = %d\n", getppid());
		wait(&status);
		exit(3);
	} else if(p2 > 0 && p4 == 0){ // 6
		// printf("p6 pid = %d\n", getpid());
		// printf("p6 ppid = %d\n", getppid());
		exit(6);
	} else if(p2 == 0 && p4 > 0){ //2
		// printf("p2 pid = %d\n", getpid());
		// printf("p2 ppid = %d\n", getppid());
		wait(&status);
		wait(&status);
		exit(2);
	} else if(p2 == 0 && p4 == 0){ // 5
		// printf("p5 pid = %d\n", getpid());
		// printf("p5 ppid = %d\n", getppid());
		exit(5);
	}

	exit(-1);
}