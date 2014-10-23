#include <iostream>
#include <cstring>

class profile{

	private:

		char name_[32];
		int age_;
		char address_[128];

	public:

		profile();
		void set_profile(char name[], int age, char address[]);
		char *get_name();
		int get_age();
		char *get_address();
		virtual void show();

};

class detail : public profile{

	private:
	
		char phonenumber_[16];
		char sex_;
		int height_;
		int weight_;

	public:

		detail();
		void set_detail(char name[], int age, char address[], char phonenumber[], char sex, int height, int weight);
		char *get_phonenumber();
		char get_sex();
		int get_height();
		int get_weight();
		void show();

};

profile::profile(){

	strcpy(name_, "(no name)");
	age_ = 0;
	strcpy(address_, "(no address)");

}

void profile::set_profile(char name[], int age, char address[]){

	strcpy(name_, name);
	age_ = age;
	strcpy(address_, address);

}

char * profile::get_name(){

	return name_;

}

int profile::get_age(){

	return age_;

}

char * profile::get_address(){

	return address_;

}

void profile::show(){

	std::cout << "name_ = " << get_name() << std::endl;
	std::cout << "age_ = " << get_age() << std::endl;
	std::cout << "address_ = " << get_address() << std::endl;

}

detail::detail(){

	strcpy(phonenumber_, "(no phone)");
	sex_ = 0;
	height_ = 0;
	weight_ = 0;

}

void detail::set_detail(char name[], int age, char address[], char phonenumber[], char sex, int height, int weight){

	set_profile(name, age, address);
	
	strcpy(phonenumber_, phonenumber);
	sex_ = sex;
	height_ = height;
	weight_ = weight;

}

char *detail::get_phonenumber(){

	return phonenumber_;

}

char detail::get_sex(){

	return sex_;

}

int detail::get_height(){

	return height_;

}

int detail::get_weight(){

	return weight_;

}

void detail::show(){

	profile::show();

	std::cout << "phonenumber_ = " << get_phonenumber() << std::endl;
	std::cout << "sex_ = " << (int)get_sex() << std::endl;
	std::cout << "height_ = " << get_height() << std::endl;
	std::cout << "weight_ = " << get_weight() << std::endl;

}

int main(){

	profile *p = NULL;

	p = new profile();

	p->set_profile("test1", 20, "tokyo");
	p->show();

	delete p;
	p = NULL;

	std::cout << std::endl;

	detail *d = NULL;

	d = new detail();

	d->set_detail("test2", 30, "osaka", "00001111", 1, 160, 55);
	p = (profile *)d;
	p->show();

	std::cout << std::endl;
	p->profile::show();

	delete d;
	d = NULL;
	p = NULL;

	return 0;

}