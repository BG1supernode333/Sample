#include <stdio.h>

struct profile_data{
	char name[32];
	int age;
	char address[128];
};

int main(void){

	struct profile_data prof;

	printf("name: ");
	scanf("%s", prof.name);

	printf("age: ");
	scanf("%d", &prof.age);

	printf("address: ");
	scanf("%s", prof.address);

	printf("--------------------\n");
	printf("prof.name: %s\n", prof.name);
	printf("prof.age: %d\n", prof.age);
	printf("prof.address: %s\n", prof.address);
	printf("--------------------\n");

	return 0;

}