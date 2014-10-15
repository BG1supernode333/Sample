#include <stdio.h>
#include <string.h>

int main(void){

	char xyz[64];
	size_t input_str_len;
	int x = 0;
	int y = 0;
	int z = 0;

	printf("x y z: ");
	fgets(xyz, 64, stdin);
	input_str_len = strlen(xyz);
	if (input_str_len > 0 && xyz[input_str_len - 1] == '\n'){
		xyz[input_str_len - 1] = '\0';
	}

	sscanf(xyz, "%d %d %d", &x, &y, &z);

	printf("x: %d\n", x);
	printf("y: %d\n", y);
	printf("z: %d\n", z);

	return 0;

}