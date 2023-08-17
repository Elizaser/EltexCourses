#include "calculator.h"
void PrintMenu(char **menu, int numberMenuItem) {
	// system("clear");
	printf("Меню\n");
	for(int  i = 0; i < numberMenuItem; i++) {
		printf("%d) %s\n", i + 1, menu[i]);
	}
}
void** LoadingLibraries(int argc, char* argv[], int *numberMenuItem) {
	void **fdLibrary;
	*numberMenuItem = argc;
	fdLibrary = (void**)malloc(*numberMenuItem*sizeof(void*));

	for(int  i = 0, j = 1; j < argc; i++, j++) {
		fdLibrary[i] = dlopen(argv[j], RTLD_LAZY);
		if(fdLibrary[i] == 0) {
			*numberMenuItem --;
			i--;
			continue;
		}
	} 
	return fdLibrary;
}
char** MenuFormation(void **fdLibrary, int numberMenuItem) {
	char **menu = (char **)malloc(numberMenuItem*sizeof(char*));

	for(int i = 0; i < numberMenuItem - 1; i++) {
		menu[i] = (char*)malloc(sizeNameMenuItem*sizeof(char));
		strcpy(menu[i], dlsym(fdLibrary[i], "Name"));
	}

	menu[numberMenuItem - 1] = (char*)malloc(sizeNameMenuItem*sizeof(char));
	strcpy(menu[numberMenuItem - 1], "Выход");

	return menu;
}
