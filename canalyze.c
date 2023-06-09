#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n",argv[0]);
        return 1;
    }

    char* filename = argv[1];
    
    FILE*fp = fopen(filename,"r");
    if (fp == NULL) {
    	printf("Error: failed to opened file %s\n",filename);
    	return 1;
	}
	
	char functionName[256];
	while (1){
		printf("Input function:");
		if (scanf("%s", functionName) != 1)
		{
			printf("Failed to read function name, try again\n");
			continue;
		}
		break;
	}
	
	fseek(fp,0,SEEK_END);
	long fsize = ftell(fp);
	fseek(fp,0,SEEK_SET);
	char*buffer = (char*)malloc(fsize + 1);
	fread(buffer,fsize,1,fp);
	fclose(fp);
	buffer[fsize] = '0';
	
	int lineNumber = 1;
	char*line = strtok(buffer, "\n");
	while (line != NULL) {
		if (strstr(line,functionName)!= NULL && strstr(line,"(") != NULL && strstr(line,"(") != NULL){
			printf("%d: %s\n",lineNumber,line);
		}
		lineNumber++;
		line= strtok(NULL,"\n");
	}
	free(buffer);
	return 0;
}

