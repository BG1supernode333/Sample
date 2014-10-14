#include <stdio.h>

int main(void){

	int i;
	int n;
	int x = 0;

	printf("n: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++){

		x = x + i;

		if (i == 1){
			printf("sum(1) = %d\n", x);
		}
		else if (i == 2){
			printf("sum(1,2) = %d\n", x);
		}
		else{
			printf("sum(1, ..., %d) = %d\n", i, x);
		}

	}

	printf("sum 1 to %d: %d\n", n, x); 

	return 0;

}