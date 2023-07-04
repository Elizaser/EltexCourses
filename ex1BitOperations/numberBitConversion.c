#include <stdio.h>

#define kCountBytes  4
#define kCountBits  8

void PrintBytes(int);
int ReplacementByte(int*, int, unsigned char);

int main()  {
	int a = 0xDDCCBBAA;
	
	PrintBytes(a);
	ReplacementByte(&a, 3, 0x15);
	PrintBytes(a);

	return 0;
}

void PrintBytes(int a) {
	unsigned char c;
	
	printf("\n");
	for(int i = 0; i <  kCountBytes; i++){
		c = (a&0xFF);
		printf("bytes of %d :%x\n", i + 1, c);
		a = a>>kCountBits;
	}
}

int ReplacementByte(int *a, int byteNumber, unsigned char byte) {
	int mask2 = byte << (kCountBits * (byteNumber - 1));
	int mask1 = 0xFFFFFFFF;

	if(byteNumber > kCountBytes || byteNumber < 0) {
		printf("Такого байта в числе нет\n");
		return -1;
	}

	switch(byteNumber){
		case 1:
			mask1 = 0xFFFFFF00;
			break;
		case 2:
			mask1 = 0xFFFF00FF;
			break;
		case 3:
			mask1 = 0xFF00FFFF;
			break;
		case 4:
			mask1 = 0x00FFFFFF;
	}	

	*a = *a & mask1 | mask2;

	return 0;  
}
