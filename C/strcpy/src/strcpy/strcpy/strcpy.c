#include <stdio.h>
#include <string.h>

int main(void){

	char str1[256] = {0};
	char str2[256] = {0};

	printf("str1: ");
	scanf("%s", str1);

	printf("-----strcpy before-----\n");
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	printf("-----------------------\n");

	strcpy(str2, str1);

	printf("-----strcpy after-----\n");
	printf("str1 = %s\n", str1);
	printf("str2 = %s\n", str2);
	printf("-----------------------\n");

	return 0;

}