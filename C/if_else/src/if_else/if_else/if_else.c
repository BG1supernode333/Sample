#include <stdio.h>

int main(void){

	int x;
	int y;

	printf("x: ");
	scanf("%d", &x);

	printf("y: ");
	scanf("%d", &y);

	if (x > 0) printf("x = %d, x > 0\n", x);
	if (x < 0) printf("x = %d, x < 0\n", x);
	if (x == 0) printf("x = 0\n");

	if (y == 10){
		
		printf("y is 10.\n");

	}
	else{

		printf("y is not 10.\n");

	}

	if (x + y > 0){

		printf("x + y > 0, x + y = %d\n", x + y);

	}
	else if (x + y == 0){

		printf("x + y = 0\n");

	}
	else{

		printf("x + y < 0, x + y = %d\n", x + y);

	}

	return 0;

}