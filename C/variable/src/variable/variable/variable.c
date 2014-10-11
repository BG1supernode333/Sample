#include <stdio.h>

int main(void){

	int x;
	int a;
	int b = 10;

	a = 20;

	printf("a = %d, b = %d\n", a, b);

	b = 30;

	printf("a = %d, b = %d\n", a, b);

	x = a + b;

	printf("a = %d, b = %d, x = (a + b) = %d\n", a, b, x);

	return 0;

}