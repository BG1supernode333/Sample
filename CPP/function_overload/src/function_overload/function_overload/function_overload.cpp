#include <iostream>
#include <cstring>

class form_buf{

	private:

		int size_;
		char *buf_;

	public:

		void create(int size);
		void create(int size, char *str);
		void destroy();
		void set(char *str);
		char *get();
		int get_size();

};

void form_buf::create(int size = 32){

	size_ = size;
	buf_ = new char[size + 1];

}

void form_buf::create(int size, char *str){

	create(size);
	set(str);

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

	fbuf.create();
	fbuf.set("ABCDE");
	std::cout << "fbuf.get() = " << fbuf.get() << std::endl;
	fbuf.destroy();

	fbuf2.create(20, "hoge foo bar");
	std::cout << "fbuf2.get() = " << fbuf2.get() << std::endl;
	fbuf2.destroy();

	return 0;

}