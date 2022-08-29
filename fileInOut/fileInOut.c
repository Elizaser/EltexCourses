#include<stdio.h>
#include<stdlib.h>

void fileIn(FILE *fp) {
	char str[] = "So sweet honey that, finally, he is bitter.";

    if(fwrite(str, 1, sizeof(str), fp) !=  sizeof(str)) {
    	if(feof(fp)) {
    		printf("конец файла\n");
    	} else {
			perror("filewrite");
        	exit(2);
    	}
    }
}
void fileOut(FILE *fp) {
	long size;
	char *str;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	str = (char*)malloc(size * sizeof(char));
	printf("size  = %ld\n", size);

	fseek(fp, -2, SEEK_END);
	for(int  i = 0; i < size - 1; i++) {
		if(fread(&str[i], 1, 1, fp) != 1) {
			perror("fileread");
        	exit(3);
		}
		fseek(fp, -2, SEEK_CUR);
	}
	printf("text: %s\n", str);	
	free(str);
}

int main() {
	FILE *fp;
	fp = fopen("test.txt", "r+");
	if (fp == NULL) {
        perror("fileopen");
        exit(1);
    }

	fileIn(fp);
	fileOut(fp);
 	fclose(fp);
	exit(0);
}
