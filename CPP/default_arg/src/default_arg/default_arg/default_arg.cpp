#include <iostream>
#include <cstring>

class form_buf{

	private:

		int size_;
		char *buf_;

	public:

		void create(int size);
		void destroy();
		void set(char *str);
		char *get();
		int get_size();

};

void form_buf::create(int size = 32){

	size_ = size;
	buf_ = new char[size + 1];

}

void form_buf::destroy(){

	delete [] buf_;
	buf_ = NULL;
	size_ = 0;

}

void form_buf::set(char *str){

	strncpy(buf_, str, size_);
	buf_[size_] = '\0';

}

char * form_buf::get(){

	return buf_;

}

int form_buf::get_size(){

	return size_;

}

int main(){

	form_buf fbuf;
	form_buf fbuf2;

	std::cout << "default case" << std::endl;

	fbuf.create();
	
	std::cout << "fbuf.get_size() = " << fbuf.get_size() << std::endl;

	fbuf.destroy();
	
	std::cout << "size 64 case" << std::endl;

	fbuf2.create(64);

	std::cout << "fbuf2.get_size() = " << fbuf2.get_size() << std::endl;
	
	fbuf2.destroy();

	return 0;

}