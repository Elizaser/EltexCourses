#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculator.h"
#include "libraryMath.h"

int main(void) {

	int menuItem;
	
	setlocale(LC_ALL, "");

	system("clear");
	PrintMenu();
	while(1) {
		printf("Введите пункт меню: ");
		scanf("%1d", &menuItem);
		switch(menuItem) {
		case 1:
			MenuItemTask('+');
			break;
		case 2:
			MenuItemTask('-');
			break;
		case 3:
			MenuItemTask('*');
			break;
		case 4:
			MenuItemTask('/');
			break;
		case 5:
			printf("До свидания!\n");
			exit(0);
		default:
			printf("Такого пункта меню нет\n");
			continue;
		}
		system("clear");
		PrintMenu();
	}
	return -1;
}