#include <stdio.h>
#include <dlfcn.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int printMenuItem();
int main () 
{
	int button = 0;
	int exitButton = 0;
 
    void *handle;
	void (*calculate)(); 
   
	
	DIR *dirp;
	struct dirent *entry;
	int fileCount = 0;


	dirp = opendir("plugins");
	if (!dirp) {
        perror("diropen");
        exit(1);
    }

    exitButton = printMenuItem(entry, dirp, handle);
    seekdir(dirp, 0);
   
	do {
		printf("Введите пункт меню: ");
		scanf("%d", &button);
		fileCount = 0;
		seekdir(dirp, 0);
		while((entry = readdir(dirp)) != NULL) {
			if (entry->d_type == DT_REG) {
				if(fileCount + 1 == button) {
					handle = dlopen(entry->d_name, RTLD_LAZY);
					if(!handle) {
						fputs(dlerror(), stderr);
						exit(2);
					}
			  		calculate = dlsym(handle, "calculate");
		  			if (calculate == NULL) {
				    fputs(dlerror(), stderr);
				    exit(3);
					}
					calculate();
					break;
		  		}
				fileCount++;
	    	}
		}
		// printf("Введите пункт меню: ");
		// scanf("%d", &button);
	} while(button != exitButton);
	closedir(dirp);
	
	return 0;
}

int printMenuItem(struct dirent *entry, DIR *dirp, void *handle) 
{
	int fileCount = 0;
	void (*printMenuItem)();

	system("clear");
	printf("Меню\n");
	while((entry = readdir(dirp)) != NULL) {
		 if (entry->d_type == DT_REG) {
			handle = dlopen(entry->d_name, RTLD_LAZY);
			if(!handle) {
    			fputs(dlerror(), stderr);
    			exit(2);
    		}
			printMenuItem = dlsym(handle, "menuItem");
			if (printMenuItem == NULL) {
			    fputs(dlerror(), stderr);
			    exit(3);
		  	}
			printf("%d. %s\n", fileCount + 1, printMenuItem);
			fileCount ++;
		}
    }
    printf("%d. Выход\n", ++fileCount);
    return fileCount;
}