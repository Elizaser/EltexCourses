#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define SIZE_NAME 10
#define SIZE_LASTNAME 20
#define SIZE_numberPhone 11

struct user{
	char name[SIZE_NAME];
	char lastname[SIZE_LASTNAME];
	char numberPhone[SIZE_numberPhone];
};

int curCountUsers;
struct user *users; 


void printMenu();
void allUsers();
void exitMenuItem();
void printAllUsers();
void printUser(struct user user);
int checkMemory();
void addUser();
void sort();
void assignmentStruct(struct user *user1, struct user user2);
void deleteUser();
void clearUser(struct user *user);
void searchUser();

int main(void) 
{
	int menuItem;

	curCountUsers = 0;
	users = NULL;
	
	setlocale(LC_ALL, "");

	printMenu();
	while(1) {
		scanf("\n%d", &menuItem);
		switch(menuItem) {                        
		case 1: 
			allUsers(users); 
			break;
		case 2: 
			addUser(users);
			break;                             
		case 3:
			deleteUser(users);
			break;
		case 4:
			searchUser(users);
			break;
		case 5:
			printf("До свидания!\n");
			free(users);
			exit(0);
		default:
			printf("Такого пункта меню нет. Попробуйте заново\n");
			continue;
		}
		printMenu();
	}

	return -1;
}

void printMenu()
{
	system("clear");
	printf("Меню\n");
	printf("1. Вывести все\n");
	printf("2. Добавить контакт\n");
	printf("3. Удалить контакт\n");
	printf("4. Поиск по имени\n");
	printf("5. Выход\n");
}


void allUsers() {
	system("clear");	
	if (curCountUsers == 0) {
		printf("Записей нет\n");	
	} else {
		printAllUsers(users);
	} 
	exitMenuItem();
}

void exitMenuItem() {
	char exit[4];
	printf("Если хотите выйти напишите \"exit\"\n");
	do {
		scanf("%s", &exit);
	} while(strcmp(exit, "exit") != 0);
}

void printAllUsers() {
	for(int i = 0; i < curCountUsers; i++) {
		printf("%d)", i + 1);
		printUser(users[i]);
	}
}
void printUser(struct user user) {
		printf("\tname =  %s\n", user.name);
		printf("\tlastname = %s\n", user.lastname);
		printf("\tnumberPhone = %s\n", user.numberPhone);
}

void addUser() {
	struct user newUser;


	system("clear");
	printf("\nВведите имя: ");
	scanf("%10s", &newUser.name);
	printf("\nВведите фамилию: ");
	scanf("%20s", &newUser.lastname);
	printf("\nВведите номер  телефона: ");
	scanf("%11s", &newUser.numberPhone);  

	curCountUsers++;
	users = (struct user*)realloc(users, curCountUsers * sizeof(struct user));
	assignmentStruct(&users[curCountUsers - 1], newUser);   
	sort(users);
}
void sort() {
	struct user tmpRevers;
	for(int i = 0; i < curCountUsers; i++) {
		for(int j = i + 1; j < curCountUsers; j++) {
			if(strcmp(users[i].name, users[j].name) > 0 && strcmp(users[j].name, "\0") != 0 || strcmp(users[i].name, "\0") == 0) {
				assignmentStruct(&tmpRevers, users[i]);
				assignmentStruct(&users[i], users[j]);
				assignmentStruct(&users[j], tmpRevers);
			}
		}
	}
}
void assignmentStruct(struct user *user1, struct user user2)  {
	strcpy(user1->name, user2.name);
	strcpy(user1->lastname, user2.lastname);
	strcpy(user1->numberPhone, user2.numberPhone);
}

void deleteUser() {
	int numberUser;

	system("clear");
	printAllUsers(users);
	do {
		printf("\nВведите номер пользователя для удаления(от 1 до %d) или -1 для выхода: ", curCountUsers);
		scanf("%d", &numberUser);
		if(numberUser == -1) return;
	} while (numberUser < 1 || numberUser  > curCountUsers);

	clearUser(&users[numberUser - 1]);
	sort(users);
	curCountUsers--;
	users = (struct user*)realloc(users, curCountUsers * sizeof(struct user));
}
void clearUser(struct user *user) {
	strcpy(user->name, "\0");
	strcpy(user->lastname, "\0");
	strcpy(user->numberPhone, "\0");
}
void searchUser() {
	int l, r, middle;
	char soughtName[SIZE_NAME];

	system("clear");
	printAllUsers(users);

	printf("Введите имя для поиска или exit для выхода: ");
	scanf("%s", &soughtName);
	while(strcmp(soughtName, "exit") != 0) {
		l = 0;
		r = curCountUsers - 1;
		while ( l < r) {
			middle = (l + r) / 2;
				if(strcmp(users[middle].name, soughtName) < 0) {
					l = middle + 1; 
				} else {
					r = middle;
				}
		}
		for(int  i = l; i < curCountUsers && strcmp(users[i].name, soughtName) == 0; i++) {
			printf("%d) ", i + 1);
			printUser(users[i]);
		}
		printf("Введите имя для поиска или exit для выхода: ");
		scanf("%s", &soughtName);
	}
}