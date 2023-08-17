#include "plus.h"
double Calculate() {
	double a, b, result;

	printf("Введите 2  числа  в формате: a + b\n");
	while(scanf("%lf + %lf", &a, &b) != 2) {
		printf("Неверный формат\n");
		while(fgetc(stdin) != '\n');
	}

	return Plus(a, b);
}

double Plus(double a, double b){
	return a + b;	
}