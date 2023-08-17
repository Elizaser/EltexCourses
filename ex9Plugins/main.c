#include "calculator.h"


int main(int argc, char* argv[]) {
	void **fdLibrary;
	char **menu;
	int numberMenuItem;
	int curMenuItem;
	double (*pFunc)();
	double result;
	int ex;

	fdLibrary = LoadingLibraries(argc, argv, &numberMenuItem);
	menu = MenuFormation(fdLibrary, numberMenuItem);
	
	while(1) {
		PrintMenu(menu, numberMenuItem);

		do {
			printf("Введите пункт меню: ");
			scanf("%1d", &curMenuItem);
		} while(curMenuItem < 1 || curMenuItem > numberMenuItem);
		if(curMenuItem == numberMenuItem) break;

		system("clear");
		pFunc = dlsym(fdLibrary[curMenuItem - 1], "Calculate");

		do {
			result = pFunc();
			printf("Ответ: %.3lf\n", result);
			printf("Вы хотитете выйти?(1\\0): ");
			scanf("%d", &ex);
			while(fgetc(stdin) != '\n');
		} while (ex != 1);
	}

	for(int  i = 0; i < numberMenuItem -1; i++) {
		dlclose(fdLibrary[i]);
	}
	free(fdLibrary);
	for(int  i = 0; i < numberMenuItem; i++) {
		free(menu[i]);
	}
	free(menu);
	return 0;
}