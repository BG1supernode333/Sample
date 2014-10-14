#include <stdio.h>
#include <string.h>

int main(void){

	char filename[256];
	size_t len;
	FILE *fp;
	char buf[256];

	printf("filename: ");

	fgets(filename, 256, stdin);

	len = strlen(filename);
	if (len > 0 && filename[len - 1] == '\n'){
		filename[len - 1] = '\0';
	}

	fp = fopen(filename, "r");
	if (fp == NULL){
		printf("fopen error!\n");
		return -1;
	}

	while (1){

		memset(buf, 0, 256);

		fgets(buf, 256, fp);
		
		len = strlen(buf);
		if (len > 0 && buf[len - 1] == '\n'){
			buf[len - 1] = '\0';
		}

		printf("%s\n", buf);

		if (feof(fp)){
			return -1;
		}

	}

	fclose(fp);

	return 0;

}