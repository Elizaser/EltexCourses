#include <stdio.h>
char menuItem[] = "Умножение";
void calculate() {	
	int a = 0, b = 0, result = 0;
	printf("Введите два числа через пробел для умножения: ");
	scanf("%d %d", &a, &b);
	result  = mult(a, b);
	printf("%d * %d = %d\n", a, b, result);
}

int mult  (int a, int b) {
	return a * b;
}