#include <stdio.h>
#include <ctype.h>

int main(void){

	char ch[2] = {0};

	printf("c: ");
	scanf("%c", ch);

	if (isalpha(ch[0])){

		printf("%c is alphabet.\n", ch[0]);

	}
	
	return 0;

}