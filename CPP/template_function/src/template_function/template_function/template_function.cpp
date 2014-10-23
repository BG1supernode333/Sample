#include <iostream>

template <typename T> void swap(T &a, T &b);

int main(){

	int a = 10;
	int b = 20;

	std::cout << "a: " << a << ", b: " << b << std::endl;
	swap(a, b);
	std::cout << "a: " << a << ", b: " << b << std::endl;

	char ch_x = 'X';
	char ch_y = 'Y';

	std::cout << "ch_x: " << ch_x << ", ch_y: " << ch_y << std::endl;
	swap(ch_x, ch_y);
	std::cout << "ch_x: " << ch_x << ", ch_y: " << ch_y << std::endl;

	return 0;

}

template <typename T> void swap(T &a, T &b){

	T tmp;

	tmp = a;
	a = b;
	b = tmp;

}