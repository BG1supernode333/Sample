#include <stdio.h>

int main(void){

	int x;
	int y;
	int z;
	char x_y_z[64];

	printf("x: ");
	scanf("%d", &x);

	printf("y: ");
	scanf("%d", &y);

	printf("z: ");
	scanf("%d", &z);

	sprintf(x_y_z, "(x, y, z) = (%d, %d, %d)", x, y, z);

	printf("%s\n", x_y_z);

	return 0;

}