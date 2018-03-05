#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include <sstream>


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

std::vector<struct StudentRecord> students;


// STUB(addStudent)
//Method to check through the vector for a record with the same student no.
//If a duplicate is found it returns the index, else -1
int isDuplicate(std::string searchNo){
  std::string studentNo;
  for(std::vector<int>::size_type i = 0; i != students.size(); i++) {
          studentNo = students[i].studentNo;
          // std::cout << studentNo << '\n';
          if(searchNo==studentNo){
            return i;
          }
}
  return -1;
}
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
  int duplicate_index = isDuplicate(studentNo);
  if(duplicate_index==-1){
    students.push_back(student);
    std::cout << student.name << " was added successfully!\n";

  }else{
    students[duplicate_index]=student;
    std::cout << "Duplicate found, record updated successfully." << '\n';
  }

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

  // }
  // strcpy(student.name,name);
  // strcpy(student.surname,surname);
  // strcpy(student.studentNo,studentNo);
  // strcpy(student.classRecord,classRecord);
}


// STUB(readDB)

int getAvg(std::string line){
  std::istringstream ss(line);
  std::string token;
  int numerator = 0;
  int denominator =0;
  int num;
  while (ss>>num){//std::getline(ss, token, ' ')){
    // std::cout << num << '\n';
    numerator += num;//std::stoi(token);
    denominator++;
  }

  return numerator/denominator;
}

std::vector<std::string> getLines(){
  std::vector<std::string> lines;
  std::string line;
  std::ifstream dbFile ("db.txt");
  if (dbFile.is_open())
  {
    while ( getline (dbFile,line) )
    {
      std::cout << line << " - read into db\n";
      lines.push_back(line);
    }
    dbFile.close();
  }

  else std::cout << "Unable to open file";
  return lines;
}

//Returns a student object from a string with student data
struct StudentRecord getStudent(std::string line){
  struct StudentRecord student;
  std::istringstream ss(line);
  std::string token;
  std::getline(ss, token, ',');
  student.name = token;
  std::getline(ss, token, ',');
  student.surname = token;
  std::getline(ss, token, ',');
  student.studentNo = token;
  std::getline(ss, token, ',');
  student.classRecord = token;
  return student;

}

//
void readStudents(std::vector<std::string> v){
  for(std::vector<int>::size_type i = 0; i != v.size(); i++) {
    // std::cout<<getStudent(v[i]).name;
    students.push_back(getStudent(v[i]));
}

}

void readDB(){
  readStudents(getLines());

}
void saveDB(){
  std::ofstream dbFile;
  dbFile.open("db.txt",std::ios::app);
  std::string name, surname, studentNo, classRecord;
    for(std::vector<int>::size_type i = 0; i != students.size(); i++) {
      name = students[i].name;
      surname = students[i].surname;
      studentNo = students[i].studentNo;
      classRecord = students[i].classRecord;

      dbFile<<name<<","<<surname<<","<<studentNo<<","<<classRecord<<"\n";
    }
    dbFile.close();

    std::cout << "Database Saved!" << '\n';
}
void displayStudentData(){
  bool found = false;
  std::string searchNo;
  std::cout << "\nEnter Student Number:" << '\n';
  std::getline(std::cin,searchNo);
  std::string name, surname, studentNo, classRecord;
    for(std::vector<int>::size_type i = 0; i != students.size(); i++) {
            studentNo = students[i].studentNo;
            // std::cout << studentNo << '\n';
            if(searchNo==studentNo){

              name = students[i].name;
              surname = students[i].surname;
              classRecord = students[i].classRecord;
              std::cout << "\nStudent found!" << "\nName: "<<name<<"\nSurname: "<<surname<<"\nStudent Number: "<<studentNo<<"\nClass Record: "<<classRecord<<"\n";
              found = true;
              break;
            }
}
if(found == false)std::cout << "Student not found." << '\n';

}
void gradeStudent(){
  bool found = false;
  std::string searchNo;
  std::cout << "\nEnter Student Number:" << '\n';
  std::getline(std::cin,searchNo);
  std::string studentNo, classRecord;
  int avg;
    for(std::vector<int>::size_type i = 0; i != students.size(); i++) {
            studentNo = students[i].studentNo;
            // std::cout << studentNo << '\n';
            if(searchNo==studentNo){
              classRecord = students[i].classRecord;
              avg = getAvg(classRecord);
              found = true;
              break;
            }
}
if(found == false)std::cout << "Student not found." << '\n';
else std::cout << "Average: "<<avg << '\n';
}

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
