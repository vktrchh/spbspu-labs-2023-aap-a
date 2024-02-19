#include <iostream>

#include "read_string.h"
#include "convert_to_lowercase.h"
#include "strings_merge.h"

int main()
{
  const char defaultSize = 100;

  char * firstString = nullptr;
  char * secondString = nullptr;
  char * loweredString = nullptr;
  char * mergedString = nullptr;
  try
  {
    firstString = kovtun::readString(std::cin);
    secondString = kovtun::readString(std::cin);

    if (firstString[0] == '\0' && secondString[0] == '\0')
    {
      delete [] firstString;
      delete [] secondString;
      std::cerr << "empty input\n";
      return 2;
    }

    loweredString = new char[defaultSize]();
    kovtun::convertToLowercase(loweredString, firstString);

    mergedString = new char[defaultSize]();
    mergedString = kovtun::mergeStrings(mergedString, firstString, secondString);
  }
  catch (...)
  {
    delete [] firstString;
    delete [] secondString;
    delete [] loweredString;
    delete [] mergedString;

    std::cerr << "unexpected error occurred\n";
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

