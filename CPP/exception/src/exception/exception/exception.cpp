#include <iostream>

int main(){

	int x;

	std::cout << "x: ";
	std::cin >> x;

	try{

		if (x == 0){

			std::cout << "throw: zero" << std::endl;
			throw "zero";

		}
		else if (x < 0){

			std::cout << "throw: " << x << std::endl;
			throw x;

		}

	}
	catch (char *str){

		std::cout << "catch: " << str << std::endl;
		return -1;

	}
	catch (int i){

		std::cout << "catch: " << i << std::endl;
		return i;

	}

	std::cout << "end" << std::endl;

	return 0;

}