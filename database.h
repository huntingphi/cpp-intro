#include <string>

namespace MLLJET002{
void clear(void);

#define STUB(method) void method(){\
  std::cout<<"Todo: "<<#method<<"\n";\
}

int displayMenu();
}
