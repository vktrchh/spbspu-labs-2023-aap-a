#include <iostream>
#include <iomanip>
#include "extendstring.h"

int main()
{
  char * string = nullptr;
  std::cin >> std::noskipws;
  string = strelyaev::extendString(std::cin);
  if (string == nullptr)
  {
    std::cerr << "Unable to create a string\n";
    return 1;
  }
  std::cout << strelyaev::checkRepDgt(string) << "\n";
  delete [] string;
  std::cin >> std::skipws;
  return 0;
}
