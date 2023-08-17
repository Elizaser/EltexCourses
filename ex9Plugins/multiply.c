#include "multiply.h"
double Calculate() {
	double a, b, result;

	printf("Введите 2  числа  в формате: a * b\n");
	while(scanf("%lf * %lf", &a, &b) != 2) {
		printf("Неверный формат\n");
		while(fgetc(stdin) != '\n');
	}

	return Multiply(a, b);
}
double Multiply(double a, double b){
	return a * b;	
}