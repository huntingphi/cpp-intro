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

std::vector<struct StudentRecord> students;
bool db_loaded = false;


// STUB(addStudent)
//Method to check through the vector for a record with the same student no.
//If a duplicate is found it returns the index, else -1
int MLLJET002::isDuplicate(std::string searchNo){
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

//Adds student to the database. When checking for duplicates it assumes that the records have
//been loaded from the text file.
void MLLJET002::addStudent(){
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


//Returns the average given the class record
int MLLJET002::getAvg(std::string line){
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

//Returns a vector with the lines in the text file
std::vector<std::string> getLines(){
  std::vector<std::string> lines;
  std::string line;
  std::ifstream dbFile ("db.txt");
  if (dbFile.is_open())
  {
    while ( getline (dbFile,line) )
    {
      std::cout << line << " - read into db successfully\n";
      lines.push_back(line);
    }
    dbFile.close();
  }

  else std::cout << "Unable to open file";
  return lines;
}

//Returns a student object from a string with student data
struct StudentRecord MLLJET002::getStudent(std::string line){
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

//Takes the vector with the file lines as a parameter and loads them into the students vector
//Using the getStudent function
void MLLJET002::readStudents(std::vector<std::string> v){
  for(std::vector<int>::size_type i = 0; i != v.size(); i++) {
    // std::cout<<getStudent(v[i]).name;
    students.push_back(getStudent(v[i]));
}

}

//Loads the file records into the students vector by using the functions defined above
void MLLJET002::readDB(){
  db_loaded = true;
  readStudents(getLines());

}

//Outputs the vector to a file in the specified format (comma seperated)
void MLLJET002::saveDB(){
  if (db_loaded==false) {
  std::cout << "The database file must be read before it can be saved." << '\n';
}else{
  std::ofstream dbFile;
  dbFile.open("db.txt");
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
}

//Displays details of a student when given a student number
void MLLJET002::displayStudentData(){
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
void MLLJET002::gradeStudent(){
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

//Clears the terminal
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
//Displays the menu
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
      std::cout << "Are you sure you want to quit? y/n" <<std::endl;
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
