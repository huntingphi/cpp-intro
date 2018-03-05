#include <string>
#include <vector>

namespace MLLJET002{
extern void clear(void);

#define STUB(method) void method(){\
  std::cout<<"Todo: "<<#method<<"\n";\
}

void addStudent();
void readDB();
void saveDB();
void gradeStudent();
void displayStudentData();
int isDuplicate(std::string searchNo);
int getAvg(std::string line);
void readStudents(std::vector<std::string> v);
struct StudentRecord getStudent(std::string line);


struct StudentRecord{
  std::string name;
  std::string surname;
  std::string studentNo;
  std::string classRecord;
};




int displayMenu();
}

// std::vector<int> students;
