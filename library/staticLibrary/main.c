#include <stdio.h>
#include "calculator.h"
void printMenu();
int main () 
{
	int button = 0;
        int a = 0, b = 0, result = 0;

	printMenu();
	printf("Введите пункт меню: ");
	scanf("%d", &button);

	do {	
		printMenu();
		switch(button) {
			case 1:
				printf("Введите два числа через пробел для сложения: ");
				scanf("%d %d", &a, &b);
				result  = add(a, b);
				printf("%d + %d = %d\n", a, b, result);
				break;
			case 2:
				printf("Введите два числа через пробел для вычитания: ");
				scanf("%d %d", &a, &b);
				result  = div(a, b);
				printf("%d - %d = %d\n", a, b, result);
				break;
			case 3:
				printf("Введите два числа через пробел для умножения: ");
				scanf("%d %d", &a, &b);
				result  = mult(a, b);
				printf("%d * %d = %d\n", a, b, result);
				break;
			case 4:
				printf("Введите два числа через пробел для деления: ");
				scanf("%d %d", &a, &b);
				result  = sub(a, b);
				printf("%d / %d = %d\n", a, b, result);
				break;
			case 5: 
				continue;
		}
		printf("Введите пункт меню: ");
		scanf("%d", &button);

	} while(button != 5);
	
	return 0;
}

void printMenu() 
{
		system("clear");
		printf("Меню\n");
		printf("1. Сложение\n");
		printf("2. Вычитание\n");
		printf("3. Умножение\n");
		printf("4. Деление\n");
		printf("5. Выход\n");

}
