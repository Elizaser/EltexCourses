#include <stdio.h>
char menuItem[] = "Сложение";
void calculate() {	
   	int a = 0, b = 0, result = 0;
	printf("Введите два числа через пробел для сложения: ");
	scanf("%d %d", &a, &b);
	result  = add(a, b);
	printf("%d + %d = %d\n", a, b, result);
}	

int add (int a, int b) {
	return a + b;
}