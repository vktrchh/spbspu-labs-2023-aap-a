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
    std::cerr << "Unable to allocate memory\n";
    return 1;
  }

  string = extendString(string, size);
  std::cout << checkRepDgt(string) << "\n";
  delete [] string;
}
