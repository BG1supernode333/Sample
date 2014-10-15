#include <stdio.h>
#include <string.h>

int main(void){

	char filename[256];
	size_t len;
	FILE *fp;
	char buf[256];
	char *p;
	int d;

	printf("filename: ");

	fgets(filename, 256, stdin);

	len = strlen(filename);
	if (len > 0 && filename[len - 1] == '\n'){
		filename[len - 1] = '\0';
	}

	fp = fopen(filename, "w");
	if (fp == NULL){
		printf("fopen error!\n");
		return -1;
	}

	while (1){

		memset(buf, 0, 256);

		fgets(buf, 256, stdin);

		len = strlen(buf);
		if (len > 0 && buf[len - 1] == '\n'){
			buf[len - 1] = '\0';
		}

		p = strstr(buf, "[end]");
		if (p != NULL){
			d = p - buf;
			buf[d] = '\0';
			fputs(buf, fp);
			break;
		}
		else{
			fputs(buf, fp);
			fputs("\n", fp);
		}

	}

	fclose(fp);

	return 0;

}