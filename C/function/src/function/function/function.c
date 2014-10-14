#include <stdio.h>

void print_inner_str(void);
void print_result_add(int x, int y);
int return_result_add(int x, int y);

int main(void){

	int x;
	int y;
	int result;

	printf("x: ");
	scanf("%d", &x);

	printf("y: ");
	scanf("%d", &y);

	print_inner_str();

	print_result_add(x, y);

	result = return_result_add(x, y);

	printf("return_result_add(x, y) = %d\n", result);

	return 0;

}

void print_inner_str(void){

	printf("inner string\n");

}

void print_result_add(int x, int y){

	printf("x + y = %d\n", x + y);

}

int return_result_add(int x, int y){

	return x + y;

}