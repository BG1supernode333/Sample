#include <iostream>

class point{

	private:

		int x;
		int y;

	public:

		point(int x, int y);
		point & operator+(const point &obj);
		point & operator=(const point &obj);
		friend std::ostream & operator<<(std::ostream &out, const point &obj); 

};

point::point(int x, int y){

	this->x = x;
	this->y = y;

}

point & point::operator+(const point &obj){

	this->x = this->x + obj.x;
	this->y = this->y + obj.y;

	return *this;

}

point & point::operator=(const point &obj){

	this->x = obj.x;
	this->y = obj.y;

	return *this;

}

std::ostream & operator<<(std::ostream &out, const point &obj){

	out << "(" << obj.x << ", " << obj.y << ")";

	return out;

}

int main(void){

	point pt(10, 20);
	point pt2(100, 200);
	point res(0, 0);

	res = pt + pt2;

	std::cout << res << std::endl;

	return 0;

}