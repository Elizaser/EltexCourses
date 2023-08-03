void PrintMenu() {
	printf("Меню\n");
	printf("1. Сложение\n");
	printf("2. Вычитание\n");
	printf("3. Умножение\n");
	printf("4. Деление\n");
	printf("5. Выход\n");
}

void MenuItemTask(char task) {
	unsigned short ex = 0;
	double a, b, result;

	char scanStr[] = "%lf   %lf";
	scanStr[4] = task;

	system("clear");
	while (ex != 1) {
		printf("Введите 2  числа для сложения в формате: a %c b\n", task);
		while(scanf(scanStr, &a, &b) != 2) {
			printf("Неверный формат\n");
			while(fgetc(stdin) != '\n');
		}

		switch(task){
			case '+':
				result = Plus(a, b);
				break;
			case '-':
				result = Minus(a, b);
				break;
			case '*':
				result = Multiply(a, b);
				break;
			case '/':
				result = Divide(a, b);
				break;	
		}
		printf("%.3lf %c %.3lf = %.3lf\n", a, task, b, result);

		printf("Вы хотитете выйти?(1\\0): ");
		scanf("%hu", &ex);
	}
}