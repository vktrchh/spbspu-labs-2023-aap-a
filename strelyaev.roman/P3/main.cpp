#include <iostream>
#include <iomanip>
#include "extendstring.h"

int main()
{
  std::cin >> std::noskipws;

  char * string = nullptr;
  size_t size = 0;
  try
  {
    size = 10;
    string = new char [10];
  }
  catch (...)
  {
    delete [] string;
    std::cerr << "Unable to allocate memory\n";
    return 1;
  }
  string = extendString(string, size);
  if (string == nullptr)
  {
    std::cerr << "Unable to allocate buffer memory\n";
    return 1;
  }
  std::cout << checkRepDgt(string) << "\n";
  delete [] string;
  return 0;
}
