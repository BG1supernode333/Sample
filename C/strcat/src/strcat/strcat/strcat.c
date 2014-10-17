#include <stdio.h>
#include <string.h>

int main(void){

	char main_str[256] = {0};
	char add_str[256] = {0};

	printf("main_str: ");
	scanf("%s", main_str);

	printf("add_str: ");
	scanf("%s", add_str);

	printf("-----strcat before-----\n");
	printf("main_str = %s\n", main_str);
	printf("add_str = %s\n", add_str);
	printf("-----------------------\n");

	strcat(main_str, add_str);

	printf("-----strcat after-----\n");
	printf("main_str = %s\n", main_str);
	printf("-----------------------\n");

	return 0;

}