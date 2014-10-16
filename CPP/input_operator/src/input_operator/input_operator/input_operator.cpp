#include <iostream>

int main(){

	int x;
	float f;
	char c;
	char str[256];
	int a;
	int b;

	std::cout << "x: ";
	std::cin >> x;
	std::cout << "f: ";
	std::cin >> f;
	std::cout << "c: ";
	std::cin >> c;
	std::cout << "str: ";
	std::cin >> str;

	std::cout << "x = " << x << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "str = " << str << std::endl;

	std::cout << std::endl;

	std::cout << "a b:";
	std::cin >> a >> b;
	
	std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;

}