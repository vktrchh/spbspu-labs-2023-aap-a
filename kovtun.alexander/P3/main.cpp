#include "read_string.h"
#include "convert_to_lowercase.h"
#include "strings_merge.h"

#include <iostream>

int main()
{
  char * firstString = nullptr;
  char * secondString = nullptr;
  char * loweredString = nullptr;
  char * mergedString = nullptr;
  try
  {
    firstString = kovtun::readString(std::cin);
    size_t firstStringLength = kovtun::getStringLength(firstString);

    loweredString = new char[firstStringLength + 1]();
    loweredString[firstStringLength] = '\0';
    kovtun::convertToLowercase(loweredString, firstString);

    secondString = kovtun::readString(std::cin);
    mergedString = kovtun::mergeStrings(firstString, secondString);
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
  std::cout << mergedString << "\n";

  delete [] firstString;
  delete [] secondString;
  delete [] loweredString;
  delete [] mergedString;

  return 0;
}
