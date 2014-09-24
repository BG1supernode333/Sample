#include <iostream>
#include <fstream>

int main(){

  std::ifstream ifs("test.txt");
  char str[256];

  if (!ifs){

    std::cout << "ifstream error!" << std::endl;
    return -1;

  }

  while (true){

    ifs >> str;
    if (ifs.eof()){
      break;
    }

    std::cout << str << std::endl;

  }

  ifs.close();

  return 0;

}
