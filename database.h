#include <string>

void clear(void)
{
system("clear");
};

#define STUB(method) void method(){\
  std::cout<<"Todo: "<<#method<<"\n";\
}
