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
    secondString = kovtun::readString(std::cin);

    if (firstString[0] == '\0' && secondString[0] == '\0')
    {
      delete [] firstString;
      delete [] secondString;
      std::cerr << "empty input\n";
      return 2;
    }

    loweredString = new char[firstStringLength + 1]();
    loweredString[firstStringLength] = '\0';
    kovtun::convertToLowercase(loweredString, firstString);

    mergedString = kovtun::mergeStrings(firstString, secondString);
  }
  catch (const std::bad_alloc & e)
  {
    // как лучше все это проверять и чистить?
    delete [] firstString;
    delete [] secondString;
    delete [] loweredString;
    delete [] mergedString;

    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (...)
  {
    delete [] firstString;
    delete [] secondString;
    delete [] loweredString;
    delete [] mergedString;

    std::cerr << "unexpected error occurred\n";
    return 3;
  }

  std::cout << loweredString << "\n";
  std::cout << mergedString << "\n";

  delete [] firstString;
  delete [] secondString;
  delete [] loweredString;
  delete [] mergedString;

  return 0;
}

