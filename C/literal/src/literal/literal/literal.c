#include <stdio.h>

int main(void){

	printf("decimal integer literal with L: %d\n", 47L);
	printf("hexadecimal integer literal: 0x%x\n", 0x2f);

	printf("float literal with f: %f\n", 0.00025f);
	printf("float literal scientific notation: %e\n", 2.5e-4);

	printf("char literal: %d\n", 'A');
	printf("byte value: 0x%x\n", 0x41);

	printf("string literal: %s\n", "ABC");
	printf("single string literal: ABC\n"); 

	return 0;

}