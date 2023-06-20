#include <stdio.h>

#define kCountBytes  4
#define kCountBits  8

void PrintBytes(int);
int ReplacementByte(int*, int, unsigned char);

int main()  {
	int a = 270533154;
	
	PrintBytes(a);
	ReplacementByte(&a, 3, 15);
	PrintBytes(a);

	return 0;
}

void PrintBytes(int a) {
	char *ptr = &a;
	printf("\n");
	for(int i = 0; i <  kCountBytes; i++) {
		printf("bytes of %d :%d\n", i + 1, *ptr);
		ptr++;
	}
}

int ReplacementByte(int *a, int byteNumber, unsigned char byte) {
	char * ptr = a;
	if(byteNumber > kCountBytes || byteNumber < 0) {
		printf("Такого байта в числе нет\n");
		return -1;
	}
	ptr+= byteNumber - 1;
	*ptr = byte;

	return 0;  
}