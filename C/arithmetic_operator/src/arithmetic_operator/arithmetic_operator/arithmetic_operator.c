#include <stdio.h>

int main(void){

	int a;
	int b;
	int result;
	
	printf("a: ");
	scanf("%d", &a);

	printf("b: ");
	scanf("%d", &b);

	result = a + b;
	printf("a(%d) + b(%d) = result(%d)\n", a, b, result);

	result = a - b;
	printf("a(%d) - b(%d) = result(%d)\n", a, b, result);

	result = a * b;
	printf("a(%d) * b(%d) = result(%d)\n", a, b, result);

	result = a / b;
	printf("a(%d) / b(%d) = result(%d)\n", a, b, result);

	result = a % b;
	printf("a(%d) %% b(%d) = result(%d)\n", a, b, result);

	return 0;

}