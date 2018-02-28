#include <string>
#include <iostream>
#include <cstdlib>

#ifndef HEADERFILE
  #define HEADERFILE
  #include "driver.h"
  #include "database.h"
#endif




int main(int argc, char** argv){
  clear();
  std::cout<<"Welcome to Student Records!"<<std::endl;
  int choice;
  do {
    choice = displayMenu();
  } while(choice!=-1);
  return 0;
}
