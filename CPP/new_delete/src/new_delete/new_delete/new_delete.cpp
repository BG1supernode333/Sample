#include <iostream>

int main(){

	int *int_ptr = NULL;
	int i;

	std::cout << "int_ptr: " << int_ptr << std::endl;
	int_ptr = new int;
	std::cout << "int_ptr: " << int_ptr << std::endl;
	std::cout << "*int__ptr: ";
	std::cin >> *int_ptr;
	i = *int_ptr;
	std::cout << "i: " << i << std::endl;
	delete int_ptr;
	std::cout << "int_ptr: " << int_ptr << std::endl;
	int_ptr = NULL;
	std::cout << "int_ptr: " << int_ptr << std::endl;
	
	std::cout << std::endl;

	int *int_array_ptr = NULL;

	std::cout << "int_array_ptr: " << int_array_ptr << std::endl;
	int_array_ptr = new int[5];
	std::cout << "int_array_ptr: " << int_array_ptr << std::endl;
	for (int x = 0; x < 5; x++){
		int_array_ptr[x] = x * 5;			
	}
	for (int x = 0; x < 5; x++){
		std::cout << "int_array_ptr[" << x << "]: " << int_array_ptr[x] << std::endl;			
	}
	std::cout << "int_array_ptr: " << int_array_ptr << std::endl;
	delete [] int_array_ptr;
	int_array_ptr = NULL;
	std::cout << "int_array_ptr: " << int_array_ptr << std::endl;

	return 0;

}