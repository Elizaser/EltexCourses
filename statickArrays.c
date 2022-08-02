#define N 5
#include <stdio.h>
#include <locale.h>

void task1();
void fillUsualMatrix(int matrix[N][N]);
void printMatrix(int matrix[N][N]);
void task2();
void fillInputArray(int array[N]);
void  printArray(int array[N]);
void reverseArray(int array[N]);
void task3();
void fillBinaryMatrix(int matrix[N][N]);
void task4();
void snailMatrix(int matrix[N][N]);


int main()
{
	setlocale(LC_ALL, "Rus");
	task1();
	task2();
	task3();
	task4();
}

void task1()
{
	int matrix[N][N];
	fillUsualMatrix(matrix);
	printf("\nВывод матрицы:\n");
	printMatrix(matrix);

}



void fillUsualMatrix(int matrix[N][N])
{
   int counter = 1;
   for(int i = 0; i < N; i++)
   {
	   for(int j = 0; j < N; j++)
	   {
   		matrix[i][j] = counter++;
	   }
   }
}

void  printMatrix(int matrix[N][N])
{
   for(int i = 0; i < N; i++)
   {
   	for(int j = 0; j < N; j++)
	   {
   		printf("\t%d ", matrix[i][j]);
	   }
	   printf("\n");
   }
   printf("\n");
}

void task2()
{
	int array[N];

	fillInputArray(array);
	printf("Введенный массив:\n");
	printArray(array);
 	reverseArray(array);
	printf("Массив в обратном порядке:\n");
	printArray(array);
}

void fillInputArray(int array[N])
{
	printf("Введите числа для массива:\n");
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &array[i]);
	}
}

void  printArray(int array[N])
{
   for(int i = 0; i < N; i++)
   {
		printf("%d ", array[i]);
   }
   printf("\n");
}


void reverseArray(int array[N])
{
	int swap;
	for(int i = 0, j = N - 1; i != j; i++,j--)
	{
		swap = array[i];		
		array[i] = array[j];
		array[j] = swap;
	}
}

void task3()
{
	int matrix[N][N];
	fillBinaryMatrix(matrix);
	printf("\nВывод двоичной матрицы, где верхний треугольник заполнен 1, а нижний 0 :\n");
	printMatrix(matrix);

}

void fillBinaryMatrix(int matrix[N][N])
{
	for(int i = 0; i < N; i++)
	{
	   for(int j = 0; j < N; j++)
   	{
   		if(j + i >= N - 1)
   			matrix[i][j] = 0;
   		else 
   			matrix[i][j] = 1;
   	}
	}
}

void task4()
{
	int matrix[N][N];
	snailMatrix(matrix);
	printf("\nВывод  матрицы заполненной улиткой :\n");
	printMatrix(matrix);

}

void snailMatrix(int matrix[N][N])
{
	int counter = 1;
	int forwardLines = 0;
	int forwardColumns = 0;
	int backLines = 0;
	int backColumns = 0;
	int border = 0; 
	while(counter < N * N + 1)
	{
		while(forwardColumns < N - border)
		{
			matrix[forwardLines][forwardColumns] = counter++;
			forwardColumns++;
		}
		forwardColumns--;//возвращение в пределы

		forwardLines++; // т.к текущая уже заполнена
		while(forwardLines < N - border) 
		{
			matrix[forwardLines][forwardColumns] = counter++;
			forwardLines++;
		}
		forwardLines--; //возвращение в пределы

		backLines = forwardLines; 
		backColumns = forwardColumns - 1; // т.к текущая уже заполнена
		while(backColumns > 0 + border)
		{
		 	matrix[backLines][backColumns] = counter++;
			backColumns--;
		}
		while(backLines > 0 + border)
		{
			matrix[backLines][backColumns] = counter++;
			backLines--;	
		}
		border++;
		forwardLines = border; 
		forwardColumns = border; // обнуление с учетом границы (0 + border)
	}
}