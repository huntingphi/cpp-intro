#include <string>
#include <iostream>
#include <cstdlib>
#include "database.h"
// using namespace std::cout;

int main(int argc, char** argv){
  clear();
std::cout<<"Welcome to Student Records!"<<std::endl;

  std::cout<<"Enter a number (or q to quit) and hit the Enter key..."<<std::endl;
  for (size_t i = 0; options[i] !=""; i++) {
    std::cout<<options[i]<<std::endl;
  }

  return 0;
}
