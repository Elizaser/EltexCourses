#include <stdio.h>
char menuItem[] = "Вычитание";
void calculate() {	
	int a = 0, b = 0, result = 0;
	printf("Введите два числа через пробел для вычитания: ");
	scanf("%d %d", &a, &b);
	result  = divi(a, b);
	printf("%d - %d = %d\n", a, b, result);
}

int divi(int a, int b) {
	return a - b;
}