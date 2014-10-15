#include <iostream>

int main(){

	int x = 20;
	float f = 0.25;
	char c = 'Z';
	char str[4] = "XYZ";

	std::cout << 10;
	std::cout << '\n';
	std::cout << 1.23;
	std::cout << '\n';
	std::cout << 'X';
	std::cout << '\n';
	std::cout << "ABC";
	std::cout << '\n';

	std::cout << '\n';

	std::cout << x;
	std::cout << '\n';
	std::cout << f;
	std::cout << '\n';
	std::cout << c;
	std::cout << '\n';
	std::cout << str;
	std::cout << '\n';

	std::cout << '\n';

	std::cout << f << " < " << 1.23 << " < "<< 10 << " < " << x << '\n';

	std::cout << '\n';

	std::cout << "ABC" << " ... " << 'X' << " ... " << "XYZ" << " ... " << c << std::endl;

	return 0;

}