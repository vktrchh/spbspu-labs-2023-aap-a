#include <iostream>
#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

int main()
{
  using namespace shabalin;
  char *finalString = nullptr;
  try
  {
    finalString = inputOfString(std::cin);
    if (finalString[0] == '\0')
    {
      delete[] finalString;
      std::cerr << "Error" << "\n";
      return 1;
    }
    std::cout << duplicateNumbers(finalString) << "\n";
    char result[] = "123";
    std::cout << makeLowerCaseString(finalString, result) << "\n";
    return 0;
  }
  catch (const std::bad_alloc &e)
  {
    delete[] finalString;
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
