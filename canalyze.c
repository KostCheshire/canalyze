#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для поиска функции в файле и вывода ее тела

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n",argv[0]);
        return 1;
    }

    char* filename = argv[1];
    
    FILE*fp = fopen(filename,"r");
    if (fp == NULL) {
    	printf("Error: failed to opened file %s\n",filename);
    	return 1;
	}
	
	fseek(fp,0,SEEK_END);
	long fsize = ftell(fp);
	fseek(fp,0,SEEK_SET);
	char*buffer = (char*)malloc(fsize + 1);
	fread(buffer,fsize,1,fp);
	fclose(fp);
	buffer[fsize] = '0';
	
	char*command = (char*) malloc(strlen("gcc -Wall -Wextra -pedantic -fsyntax-only")+strlen(filename)+1);
	sprintf(command,"gcc -Wall -Wextra -pedantic -fsyntax-only %s",filename);
	int result = system(command);
	free(command);
	if (result != 0){
		printf("Error: Program contains syntax errors!\n");
		return 1;
	}
	
	printf("The program %s is correct!\n",filename);
	
	return 0;
}

