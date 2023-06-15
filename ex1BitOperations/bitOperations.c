#include <stdio.h>
void printBytes(int);
void replacementThirdByte(int*, int, unsigned char);

int main() 
{
	int a = 0xDDCCBBAA;
	
	printBytes(a);
	replacementByte(&a, 3, 0x15);
	printBytes(a);

	return 0;
}

void printBytes(int a) {
	int countBytes = 4;
	int countBits = 8;
	unsigned char c;
	printf("\n") ;
	for(int i = 0; i <  countBytes; i++){
		c = (a&0xFF);
		printf("bytes of %d :%x\n", i + 1, c);
		a = a>>countBits;
	}
}

void replacementByte(int *a, int byteNumber, unsigned char byte) {
	int countBytes = 4;
	int countBits = 8;
	unsigned char c;

	int mask2 = byte << (countBits * (byteNumber - 1));
	int mask1 = 0xFFFFFFFF;

	if(byteNumber > countBytes) {
		printf("Такого байта в числе нет\n");
		return;
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

	*a = *a&mask1 | mask2;  
}
