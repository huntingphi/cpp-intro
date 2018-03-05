#include <string>
#include <vector>

namespace MLLJET002{
extern void clear(void);

#define STUB(method) void method(){\
  std::cout<<"Todo: "<<#method<<"\n";\
}

// void addStudent();
// void readDB();
// void saveDB();
// void displayStudentData();
// void gradeStudent();


int displayMenu();
}

// std::vector<int> students;
