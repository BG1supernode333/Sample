#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

	char str[256];
	size_t i;

	printf("str(before): ");
	scanf("%s", str);

	for (i = 0; i < strlen(str); i++){

		str[i] = toupper(str[i]);

	}

	printf("str(after): %s\n", str);

	return 0;

}