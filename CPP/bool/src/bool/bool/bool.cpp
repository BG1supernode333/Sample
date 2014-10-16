#include <iostream>

int main(){

	int int_array[5] = {3, 9, 12, 8, 2};
	bool find = false;
	int find_num = -1;

	for (int i = 0; i < 5; i++){

		if (find == false && int_array[i] >= 10){

			find = true;
			find_num = int_array[i];

		}

	}

	std::cout << "find = " << find << std::endl;
	std::cout << "find_num = " << find_num << std::endl;

	return 0;

}