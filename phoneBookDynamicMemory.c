#include <stdio.h>
#include <malloc.h>

#define SIZE 16
int N  = 0;
struct phonebook {
	long number;
	char name[SIZE];
	char surname[SIZE];
};

void printMenu();
void insertElement(struct phonebook *element);
void sort(struct phonebook *user1);
void change(struct phonebook  *a, struct phonebook *b);
void stringEquate(char *a, char *b);
void printElement (struct phonebook element);
void printElements(struct phonebook *user1);
void deleteElement(struct phonebook *user1); 
void search(struct phonebook *user1);       

int main () {
	struct phonebook *user1 = NULL;
	int button;

	system("clear");
	printMenu();
	printf("Введите пункт меню: ");
	scanf("%d", &button);		
	do {
		system("clear");
		printMenu();
		switch (button) {
			case 1:
				N++;
				user1 = (struct phonebook*)realloc(user1, 
						N * sizeof(struct phonebook));
				insertElement(&user1[N - 1]);
				sort(user1); 
				break;
			case 2: 
				if(N > 0) {
					deleteElement(user1);
					sort(user1);
					N--;	
					user1 = (struct phonebook*)realloc(user1, 
						N * sizeof(struct phonebook));
				} else 
					printf("Удалять нечего\n");
				break;
			case 3: 
				printElements(user1);
				break;
			case 4: 
				search(user1);
				break;
		}
		printf("Введите пункт меню: ");
		scanf("%d", &button);		
	}while(button != 5);

	free(user1);

	return 0;
}
void printMenu(){
	printf("Меню\n");
	printf("1.Добавить запись\n");
	printf("2.Удалить запись\n");
	printf("3.Просмотреть все записи\n");
	printf("4.Поиск записи по имени\n");
	printf("5.Выход\n");
}
void insertElement(struct phonebook *element) {
	printf("Введите имя: ");
 	scanf("%16s", &element->name);
	printf("Введите Фамилию: ");
	scanf("%16s", &element->surname);
	printf("Введите номер: ");
	scanf("%li",&element->number);
}
void sort(struct phonebook *user1) {
	int k = 0;
       	for(int i = 0; i < N; i++) {
       		for(int  j = i + 1; j < N; j++) {
			k = 0;
			do {
				if((user1[i].name[k] > user1[j].name[k] || user1[i].name[0] == '\0')
						  && user1[j].name[0] != '\0') {
					change(&user1[i], &user1[j]);
				} else if(user1[i].name[k] == user1[j].name[k] ) {
					k++;
					continue;
				}
				break;
			} while(user1[i].name[k] == user1[i].name[k]
					&& k < SIZE
				       	&& user1[j].name[0] != '\0');
		}
     }	
}

void change(struct phonebook  *a, struct phonebook *b) {
	struct phonebook *tmp = (struct phonebook*)malloc(N * sizeof(struct phonebook));
	
	tmp->number = a->number;
	a->number = b->number;
	b->number = tmp->number;

	stringEquate(tmp->name, a->name);
	stringEquate(a->name, b->name);
	stringEquate(b->name, tmp->name);
	
	stringEquate(tmp->surname, a->surname);
	stringEquate(a->surname, b->surname);
	stringEquate(b->surname, tmp->surname);
	free(tmp);	
}
void stringEquate(char a[], char b[]) {
	for(int i = 0; i < SIZE; i++) {
		a[i] = b[i];
	}
}
void printElement (struct phonebook element) {
		printf("Имя: ");
		printf("%s ", element.name);
		printf("\nФамилия: ");
		printf("%s ", element.surname);
		printf("\nНомер: %li\n", element.number);
	}
void printElements(struct phonebook *user1) {
	if(N > 0) {
		for(int i = 0; i < N; i++) {
			printf("%d) ", i + 1);
			printElement(user1[i]);
			printf("\n");
		} 
	}
	else 
		printf("Пусто\n");
			
}

void deleteElement(struct phonebook *user1) {
	int pDel = 0;

	printElements(user1);
	do {
		printf("Какой элемент вы хотите удалить? ");
		scanf("%d", &pDel);
	}while(pDel < 0 && pDel > N);

	user1[pDel - 1].name[0] ='\0';
}

void search(struct phonebook *user1) {
	int c = 0;
	char *searchName = (char*)malloc(SIZE * sizeof(char));
	
	printf("Введите искомое имя: ");
	scanf("%16s", searchName);

	for(int i = 0; i < N; i++) {
		c = 0;
		while(searchName[c] != '\0')
		{
			if(user1[i].name[c] != searchName[c]) {
				break;
			}
			c++;
		}
		if(searchName[c] == '\0') {
			printElement(user1[i]);
			printf("\n");
		}
	}
	free(searchName);
}


