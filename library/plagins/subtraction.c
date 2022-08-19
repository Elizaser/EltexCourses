#include <stdio.h>
char menuItem[] = "Деление";
void calculate() {
    int a = 0, b = 0, result = 0;  
    printf("Введите два числа через пробел для деления: ");
    scanf("%d %d", &a, &b);
    if(b == 0)
        b = 1;
    result  = sub(a, b);
    printf("%d / %d = %d\n", a, b, result);
}

int sub  (int a, int b) {
 return a / b;
}