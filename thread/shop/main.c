#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define countShops 5
#define countBuyers 3

int shops[countShops];
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int getRandom(int min, int max);

void *threadBuyer(void *args) {
	// int *shops = (int *)args;
	int need = getRandom(900, 1100);;
	int i = 0;
	int *ptr = (int*)args;

	printf("Create buyer %d, need = %d\n", *ptr, need);

	while(need != 0) {
		if (i == countShops) i = 0;
		while(i < countShops) {
			if(shops[i] != 0) {
				pthread_mutex_lock(&m);
				printf("In buyer № %d need = %d: in shop № %d. Products  = %d\n", *ptr, need, i, shops[i]);
				if (need > shops[i]) {
					need -= shops[i];
					shops[i] = 0;
				} else {
					shops[i] -= need;
					need = 0;
				}
				pthread_mutex_unlock(&m);
				break;
			}
			printf("Buyer № %d: shop № %d does not products. Next\n", *ptr, i);
			i++;
		}
		sleep(2);
	}
	return NULL;
}

void *threadLoader(void *args) {
	
	// int *shops = (int *)args;
	int i = 0;


	while (1) {
		if (i == countShops) i = 0;
		while(i < countShops) {
			if(shops[i] == 0) {
				pthread_mutex_lock(&m);
				printf("loader: shop № %d is empty. Loading products and go\n", i);
				shops[i] = 1000;
				pthread_mutex_unlock(&m);
				break;
			}
			printf("loader: shop № %d does not need products. Next\n", i);
			i++;
		}
		sleep(2);
	}
	return NULL;
}

int main(void) {
	pthread_t buyers[countBuyers];
	pthread_t loader;
	int a[countBuyers];

	srand(time(NULL));

	for(int i = 0; i < countShops; i++ )  
		shops[i] = getRandom(900, 1100);

	printf("Create shops:\n");
	for(int i = 0; i < countShops; i++ ) {
		printf("%d: %d products\n", i, shops[i]);
	}

	for(int  i = 0; i < countShops; i++) {
		a[i] = i;
		pthread_create(&buyers[i], NULL, threadBuyer, (void*)&a[i]);
	}

	pthread_create(&loader, NULL, threadLoader, NULL);

	for(int i = 0; i < countShops; i++) {
		pthread_join(buyers[i], NULL);
	}
	// pthread_join(loader, NULL);

	return 0;
}
int getRandom(int min, int max) {
	return min + rand()%(max - min + 1);
}