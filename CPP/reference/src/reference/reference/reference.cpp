#include <iostream>

void swap(int &a, int &b);

int main(){

	int a;
	int b;
	int &x = a;

	std::cout << "a: ";
	std::cin >> a;

	std::cout << "b: ";
	std::cin >> b;

	std::cout << "swap before: a = " << a << ", b = " << b << std::endl;

	swap(a, b);

	std::cout << "swap after: a = " << a << ", b = " << b << std::endl;

	std::cout << "x = " << x << std::endl;

	return 0;

}

void swap(int &a, int &b){

	int tmp;

	tmp = a;
	a = b;
	b = tmp;

}