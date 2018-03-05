#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#ifndef HEADERFILE
  #define HEADERFILE
  #include "database.h"
#endif

using namespace MLLJET002;

struct StudentRecord{
  std::string name;
  std::string surname;
  std::string studentNo;
  std::string classRecord;
};


// STUB(addStudent)
void addStudent(){
  struct StudentRecord student;
  // bool repeat = true;

  // while(repeat == true){
  // std::cin.clear();
  std::string name, surname, studentNo, classRecord;
  std::cout << "Enter student name:" << '\n';
  std::getline(std::cin, name);
  std::cout << "Enter student surname:" << '\n';
  std::getline(std::cin,surname);
  std::cout << "Enter student student number:" << '\n';
  std::getline(std::cin,studentNo);
  std::cout << "Enter student class record:" << '\n';
  std::getline(std::cin,classRecord);
  student.name = name;
  student.surname = surname;
  student.studentNo = studentNo;
  student.classRecord = classRecord;
  std::ofstream dbFile;
  dbFile.open("db.txt",std::ios::app);
  dbFile<<name<<","<<surname<<","<<studentNo<<","<<classRecord<<"\n";

  std::cout << student.name << " was added successfully!\n";
  // char input;
  // while (input !='y'&&input!='n') {
  //   std::cout << "Would you like to add another student? y/n" << '\n';
  //   std::cin>>input;
  // }
  // if (input=='y') {
  //   repeat=true;
  // }else{
  //   repeat=false;
  // }

  dbFile.close();
  // }
  // strcpy(student.name,name);
  // strcpy(student.surname,surname);
  // strcpy(student.studentNo,studentNo);
  // strcpy(student.classRecord,classRecord);
}


// STUB(readDB)

void readDB(){


}
STUB(saveDB)
STUB(displayStudentData)
STUB(gradeStudent)

void MLLJET002::clear(){
system("clear");
}

std::string options [6] = {
  "0: Add student",
  "1: Read database",
  "2: Save database",
  "3: Display given student data",
  "4: Grade student",
  "q: Quit"
};

int MLLJET002::displayMenu(){
  std::cout<<"\nEnter a number from below (or anything else to quit ) and hit the Enter key..."<<std::endl;

  for (size_t i = 0; options[i] !=""; i++) {
    std::cout<<options[i]<<std::endl;
  }
  char choice;

  std::cin>>choice;
  std::cin.ignore(1,'\n');

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
      if(input=='y'){
        choice=-1;
      }
      break;

  }
  return choice;
}

// int main(int argc, char** argv){
//   clear();
//   std::cout<<"Welcome to Student Records!"<<std::endl;
//
//   int choice;
//   do {
//     /* code */
//     choice = displayMenu();
//     // std::cout<<choice;
//
//   } while(choice!=-1);
//
//
//   return 0;
// }
