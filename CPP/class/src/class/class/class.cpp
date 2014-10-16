#include <iostream>

class profile{

	private:

		char name_[32];
		int age_;
		char address_[128];

	public:

		void set_profile(char name[], int age, char address[]);
		char *get_name();
		int get_age();
		char *get_address();

};

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

int main(){

	profile prof;
	char name[32];
	int age;
	char address[128];

	std::cout << "name: ";
	std::cin >> name;

	std::cout << "age: ";
	std::cin >> age;

	std::cout << "address: ";
	std::cin >> address;

	prof.set_profile(name, age, address);

	std::cout << "prof.name_ = " << prof.get_name() << std::endl;
	std::cout << "prof.age_ = " << prof.get_age() << std::endl;
	std::cout << "prof.address_ = " << prof.get_address() << std::endl;

	return 0;	

}