#include <string>

void clear(void);

#define STUB(method) void method(){\
  std::cout<<"Todo: "<<#method<<"\n";\
}

int displayMenu();
