#include "divide.h"
double Calculate() {
	double a, b, result;

	printf("Введите 2  числа  в формате: a / b\n");
	while(scanf("%lf / %lf", &a, &b) != 2) {
		printf("Неверный формат\n");
		while(fgetc(stdin) != '\n');
	}

	return Divide(a, b);
}
double Divide(double a, double b){
	return a / b;	
}