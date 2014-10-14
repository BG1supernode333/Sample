#include <stdio.h>

int main(void){

	int i;
	int x = 0;
	int sum_array[10] = {0};
	int j = 0;

	for (i = 1; i <= 10; i++){

		x = x + i;
		sum_array[i - 1] = x;

	}

	while (1){

		printf("which element? ");
		scanf("%d", &j);

		if (j == 0){
			printf("sum_array[%d] = sum(1) = %d\n", j, sum_array[j]);
		}
		else if (j == 1){
			printf("sum_array[%d] = sum(1, 2) = %d\n", j, sum_array[j]);
		}
		else if (j >= 2 && j <= 9){
			printf("sum_array[%d] = sum(1, ..., %d) = %d\n", j, j + 1, sum_array[j]);
		}
		else{
			break;
		}

	}

	return 0;

}