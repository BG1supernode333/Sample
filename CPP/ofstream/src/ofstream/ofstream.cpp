#include <iostream>
#include <fstream>

int main(){

  std::ofstream ofs("test.txt");
  char str[256];

  if (!ofs){

    std::cout << "ofstream error!" << std::endl;
    return -1;

  }

  while (true){

    std::cin >> str;

    if (str[0] == 'q' && str[1] == '\0'){

      break;

    }

    ofs << str << std::endl;

  }

  ofs.close();

  return 0;

}
