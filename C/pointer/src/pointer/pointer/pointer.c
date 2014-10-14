#include <stdio.h>

int main(void){

	int x;
	int *p;

	x = 10;
	p = &x;

	printf("x = %d\n", x);
	printf("&x = 0x%08p\n", &x);
	printf("p = 0x%08p\n", p);
	printf("*p =%d\n", *p);

	return 0;

}