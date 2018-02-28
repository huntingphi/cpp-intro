#include <string>
#include <iostream>
#include <cstdlib>

#ifndef HEADERFILE
  #define HEADERFILE
  #include "database.h"
#endif


#define STUB(method) void method(){\
  std::cout<<"Todo: "<<#method<<"\n";\
}

STUB(addStudent)
STUB(readDB)
STUB(saveDB)
STUB(displayStudentData)
STUB(gradeStudent)

std::string options [6] = {
  "0: Add student",
  "1: Read database",
  "2: Save database",
  "3: Display given student data",
  "4: Grade student",
  "q: Quit"
};

int displayMenu(){
  std::cout<<"\nEnter a number from below (or anything else to quit ) and hit the Enter key..."<<std::endl;

  for (size_t i = 0; options[i] !=""; i++) {
    std::cout<<options[i]<<std::endl;
  }
  char choice;

  std::cin>>choice;
  return choice;
}

int main(int argc, char** argv){
  clear();
  std::cout<<"Welcome to Student Records!"<<std::endl;

  int choice;
  do {
    /* code */
    choice = displayMenu();
    // std::cout<<choice;
    switch (choice) {
      case '0':
        addStudent();
        break;
      case '1':
        readDB();
        break;
      case '2':
        saveDB();
        break;
      case '3':
        displayStudentData();
        break;
      case '4':
        gradeStudent();
        break;
      default:
        std::cout << "Are you sure? y/n" <<std::endl;
        char input;
        std::cin>>input;
        if(input=='n'){
          continue;
        }else{
          choice=-1;
        }
        break;

    }
  } while(choice!=-1);


  return 0;
}
