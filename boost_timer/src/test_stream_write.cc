#include <iostream>
#include <iosfwd>
#include <fstream>
#include<string>

int main() {
  char buff[10];
  std::string file_name  = "test.txt";

  std::ifstream in(file_name, std::ios_base::in | std::ios_base::binary);
  if (!in.is_open()) {
    std::cout << "wrong" << std::endl;
  }

  in.read(buff, 6);
  std::cout << std::string(buff) << std::endl;
  in.close();
}
