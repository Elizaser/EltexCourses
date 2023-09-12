#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define countShops 5
#define countBuyers 3

int shops[countShops];
pthread_mutex_t m[countShops];

void *threadBuyer(void *args) {
	int need = 10000;
	int i = 0;
	int *number = (int*)args;

	printf("Create buyer %d\n", *number);

	while(need != 0) {
		printf("Buyer № %d wake up\n", *number);
		if (i == countShops) i = 0;
		while(i < countShops) {
			if(pthread_mutex_trylock(&m[i]) == 0 && shops[i] != 0) {
				need -= shops[i];
				shops[i] = 0;
				printf("Buyer № %d in shop № %d. Need = %d\n", *number, i, need);
				break;
			}
			pthread_mutex_unlock(&m[i]);
			printf("Buyer № %d in shop № %d was unable to take the products. Next\n", *number, i);
			i++;
		}
		printf("Buyer № %d sleep\n", *number);
		sleep(2);
	}
	return NULL;
}

void *threadLoader(void *args) {
	int i = 0;
	printf("Create loader\n");

	while (1) {
		printf("Loader wake up\n");
		if (i == countShops) i = 0;
		while(i < countShops) {
			if(pthread_mutex_trylock(&m[i]) == 0 && shops[i] == 0) {
				shops[i] = 1000;
				printf("loader: Loading products in shop № %d\n", i);
				break;
			}
			pthread_mutex_unlock(&m[i]);
			printf("loader: shop № %d does not loading. Next\n", i);
			i++;
		}
		printf("Loader sleep\n");
		sleep(2);
	}
	return NULL;
}

int main(void) {
	pthread_t buyers[countBuyers];
	pthread_t loader;
	int a[countBuyers];


	for(int i = 0; i < countShops; i++ )  {
		shops[i] = 1000;
		pthread_mutex_init(&m[i], NULL);
	}

	
	for(int  i = 0; i < countBuyers; i++) {
		a[i] = i;
		pthread_create(&buyers[i], NULL, threadBuyer, (void*)&a[i]);
	}
	pthread_create(&loader, NULL, threadLoader, NULL);

	for(int i = 0; i < countBuyers; i++) {
		pthread_join(buyers[i], NULL);
	}

	for(int i = 0; i < countShops; i++ )  {
		pthread_mutex_destroy(&m[i]);
	}

	return 0;
}