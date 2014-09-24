#include <iostream>
#include <string>

int main(){

  std::string str1;
  std::string str2("ABC");
  std::string str3 = "XYZ";

  str1 = "string";

  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;
  std::cout << str3 << std::endl;

  std::cout << std::endl;

  str2 = "string";

  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;
  std::cout << str3 << std::endl;

  std::cout << std::endl;

  if (str1 == str2){

    std::cout << "str1 == str2" << std::endl;

  }

  if (str2 != str3){

    std::cout << "str2 != str3" << std::endl;

  }

  std::cout << std::endl;

  str2 = str1 + "XYZ";
  str3 = "string" + str3;

  std::cout << str2 << std::endl;
  std::cout << str3 << std::endl;

  if (str2 == str3){

    std::cout << "str2 == str3" << std::endl;

  }

  return 0;

}
