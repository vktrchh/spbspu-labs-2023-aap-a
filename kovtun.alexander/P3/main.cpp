#include "read_string.h"
#include "convert_to_lowercase.h"

#include <iostream>

int main()
{
  char * firstString = nullptr;
  char * loweredString = nullptr;
  try
  {
    firstString = kovtun::readString(std::cin);
    size_t firstStringLength = kovtun::getStringLength(firstString);

    loweredString = new char[firstStringLength + 1]();
    loweredString[firstStringLength] = '\0';
    kovtun::convertToLowercase(loweredString, firstString);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "";
    return 1;
  }

  std::cout << loweredString << "\n";

  delete [] loweredString;

  return 0;
}
