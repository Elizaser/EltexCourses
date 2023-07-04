#include <stdio.h>

#define N 9

void fillMatrixAsc(int [N][N]);
void printMatrix(int [N][N]);

void fillArrayAsc(int [N]);
void printArray(int [N]);
void reverseArray(int [N]);

void fillMatrixTriangle(int [N][N]);

void fillMatrixSnail(int [N][N]);

int main(void) 
{
	int matrix[N][N] = {0};
	int array[N];
	
	//упражнение 1
	printf("Ex1\n"); 
	fillMatrixAsc(matrix);
	printMatrix(matrix);
	
	//упражнение 2
	printf("Ex2\n");
	fillArrayAsc(array);
	printArray(array);
	reverseArray(array);
	printArray(array);
	
	//упражнение 3
	printf("Ex3\n");
	fillMatrixTriangle(matrix);
	printMatrix(matrix);
	
	//упражнение 4
	printf("Ex4\n");
	fillMatrixSnail(matrix);
	printMatrix(matrix);
}

void fillMatrixAsc(int matrix[N][N]) 
{
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			matrix[i][j] = (i * N) + j + 1; 
		} 
	}
}

void printMatrix(int matrix[N][N])
{
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%5d ", matrix[i][j]); 
		} 
		printf("\n");
	}
}

void fillArrayAsc(int array[N]) 
{
	for(int i = 0; i < N; i++) {
		array[i] = i + 1; 
	}
}

void printArray(int array[N])
{
	for(int i = 0; i < N; i++) {
		printf("%d ", array[i]); 
	}
	printf("\n"); 
}
void reverseArray(int array[N])
{
	int buf;
	for(int i = 0; i < N/2; i++) {
		buf = array[i];
		array[i] =  array[N - 1 - i]; 
		array[N - 1 - i] = buf; 
	}
}

void fillMatrixTriangle(int matrix[N][N])
{
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(j + i  + 1 < N)
				matrix[i][j] = 0;
			else 
				matrix[i][j] = 1; 
		} 
	}
}
void fillMatrixSnail(int matrix[N][N])
{
	int i = 0, j = 0;
	int iter = 1; 
	int indent = 0;
	
	while(iter <= N*N) {
		matrix[i][j] = iter;
		iter++;
		if(i == indent && j < N - 1 - indent) {
			j++;
		} else if(j == N - 1 - indent && i < N - 1 - indent) {
			i++;
		} else if(i == N - 1 - indent && j > indent) {
			j--;
		} else if(j == indent && i > indent) {
			i--;
		}
		if(i - 1 - indent == 0 && j - indent == 0) indent++;
	}
}