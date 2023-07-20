#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define SIZE_PHONEBOOK 10
#define SIZE_NAME 10
#define SIZE_LASTNAME 20
#define SIZE_numberPhone 11

int curCountUsers;

struct user{
	char name[SIZE_NAME];
	char lastname[SIZE_LASTNAME];
	char numberPhone[SIZE_numberPhone];
};

void printMenu();
void allUsers(struct user users[SIZE_PHONEBOOK]);
void exitMenuItem();
void printAllUsers(struct user users[SIZE_PHONEBOOK]);
void printUser(struct user user);
int checkMemory();
void addUser(struct user users[SIZE_PHONEBOOK]);
void assignmentStruct(struct user *user1, struct user user2);
void deleteUser(struct user users[SIZE_PHONEBOOK]);
void clearUser(struct user *user);
void searchUser(struct user users[SIZE_PHONEBOOK]);

int main(void) 
{
	setlocale(LC_ALL, "");
	
	int menuItem;
	struct user users[SIZE_PHONEBOOK]; 

	curCountUsers = 0;
	
	printMenu();
	while(1) {
		scanf("\n%d", &menuItem);
		switch(menuItem) {                        
		case 1:       
			allUsers(users); 
			break;
		case 2: 
			if(!checkMemory()) continue;
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


void allUsers(struct user users[SIZE_PHONEBOOK]) {
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

void printAllUsers(struct user users[SIZE_PHONEBOOK]) {
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
void sort(struct user users[SIZE_PHONEBOOK]) {
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
int checkMemory() {
	if(curCountUsers >= SIZE_PHONEBOOK) {
		printf("Память переполнена. Нужно что-нибудь удалить!\n");
		return 0;
	}  
	return 1;
}
void addUser(struct user users[SIZE_PHONEBOOK]) {
	struct user newUser;
	struct user tmpRevers1, tmpRevers2;
	system("clear");
	printf("\nВведите имя: ");
	scanf("%10s", &newUser.name);
	printf("\nВведите фамилию: ");
	scanf("%20s", &newUser.lastname);
	printf("\nВведите номер  телефона: ");
	scanf("%11s", &newUser.numberPhone);  

	assignmentStruct(&users[curCountUsers], newUser);   
	curCountUsers++;
	sort(users);
}
void assignmentStruct(struct user *user1, struct user user2)  {
	strcpy(user1->name, user2.name);
	strcpy(user1->lastname, user2.lastname);
	strcpy(user1->numberPhone, user2.numberPhone);
}

void deleteUser(struct user users[SIZE_PHONEBOOK]) {
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
}
void clearUser(struct user *user) {
	strcpy(user->name, "\0");
	strcpy(user->lastname, "\0");
	strcpy(user->numberPhone, "\0");
}
void searchUser(struct user users[SIZE_PHONEBOOK]) {
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
		for(int  i = l; i < SIZE_PHONEBOOK && strcmp(users[i].name, soughtName) == 0; i++) {
			printf("%d) ", i + 1);
			printUser(users[i]);
		}
		printf("Введите имя для поиска или exit для выхода: ");
		scanf("%s", &soughtName);
	}
}
