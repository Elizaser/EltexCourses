#include <stdio.h>
#include <pthread.h>

#define N 5

void *threadFunc(void *args) {
	int *ptr = (int*)args;
	printf("%d\n", *ptr);
	return NULL;
}

int main(void) {
	int a[N];
	int *s;
	pthread_t thread[N];

	for(int  i = 0; i < N; i++) {
		a[i] = i;
		pthread_create(&thread[i], NULL, threadFunc, (void*)&a[i]);
	}

	for(int i = 0; i < N; i++) {
		pthread_join(thread[i], (void**)&s);
	}

	return 0;
}