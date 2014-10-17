#include <iostream>

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

int main(){

	profile prof;
	char name[32];
	int age;
	char address[128];

	std::cout << "-----set before-----" << std::endl;
	std::cout << "prof.name_ = " << prof.get_name() << std::endl;
	std::cout << "prof.age_ = " << prof.get_age() << std::endl;
	std::cout << "prof.address_ = " << prof.get_address() << std::endl;
	std::cout << "--------------------" << std::endl;

	std::cout << "name: ";
	std::cin >> name;

	std::cout << "age: ";
	std::cin >> age;

	std::cout << "address: ";
	std::cin >> address;

	prof.set_profile(name, age, address);

	std::cout << "-----set after-----" << std::endl;
	std::cout << "prof.name_ = " << prof.get_name() << std::endl;
	std::cout << "prof.age_ = " << prof.get_age() << std::endl;
	std::cout << "prof.address_ = " << prof.get_address() << std::endl;
	std::cout << "--------------------" << std::endl;

	return 0;	

}