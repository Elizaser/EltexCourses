#include <stdio.h>

#define N 10
#define SIZE 16

struct phonebook {
	long number;
	char name[SIZE];
	char surname[SIZE];
};

void initElements(struct phonebook user1[]);
void printMenu();
void insertElement(struct phonebook *element);
void sort(struct phonebook user1[]);
void change(struct phonebook  *a, struct phonebook *b);
void stringEquate(char a[], char b[]);
void printElement (struct phonebook element);
void deleteElement(struct phonebook *element); 
	      
int main () {
	struct phonebook user1[N];
	int button;
	int cAdd = 0, cDel = 0;
	char searchName[SIZE];

	initElements(&user1);
	printMenu();
	scanf("%d", &button);		
	do {
		system("clear");
		printMenu();
		if(cAdd >= N) cAdd = 0;// перезапись  элементов // от переполнения
		switch (button) {
			case 1:
				insertElement(&user1[cAdd]);
				cAdd++;
				sort(&user1);
				break;
			case 2: 
				do {
					printf("Какой элемент вы хотите удалить?(1 -10) ");
					scanf("%d", &cDel);
				}while(cDel < 0 && cDel > N);
				deleteElement(&user1[cDel - 1]);
				sort(&user1);
				break;
			case 3: 
				for(int j = 0; j < N; j++) {
					printf("%d) ", j + 1);
					printElement(user1[j]);
					printf("\n");
				}
				break;
			case 4: 
				printf("Введите искомое имя: ");
				scanf("%16s", searchName);
				search(user1, searchName);
				break;
		}
		scanf("%d", &button);		
	}while(button != 5);

	return 0;
}
void initElements(struct phonebook user1[]) {
	for(int i = 0; i < N; i++) {
		deleteElement(&user1[i]);
	}
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
void sort(struct phonebook user1[]) {
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
	struct phonebook tmp[N];
	
	tmp->number = a->number;
	a->number = b->number;
	b->number = tmp->number;

	stringEquate(tmp->name, a->name);
	stringEquate(a->name, b->name);
	stringEquate(b->name, tmp->name);
	
	stringEquate(tmp->surname, a->surname);
	stringEquate(a->surname, b->surname);
	stringEquate(b->surname, tmp->surname);
}
void stringEquate(char a[], char b[]) {
	for(int i = 0; i < SIZE; i++) {
		a[i] = b[i];
	}
}
void printElement (struct phonebook element) {
	if(element.name[0] != '\0') {
		printf("Имя: ");
		printf("%s ", element.name);
		printf("\nФамилия: ");
		printf("%s ", element.surname);
		printf("\nНомер: %li\n", element.number);
	} else 
		printf("Пусто");
}


void deleteElement(struct phonebook *element) {
	element->name[0] ='\0';
}

void search(struct phonebook user1[], char searchName[]) {
	int c = 0;
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
}


