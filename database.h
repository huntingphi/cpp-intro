#include <string>
#include <vector>

namespace MLLJET002{
extern void clear(void);

#define STUB(method) void method(){\
  std::cout<<"Todo: "<<#method<<"\n";\
}

extern int displayMenu();
}

extern std::vector<int> students;
