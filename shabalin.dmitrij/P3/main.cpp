#include <iostream>
#include <stdexcept>
#include "duplicateNumbers.h"
#include "inputOfString.h"
#include "makeLowerCaseString.h"

int main()
{
  char *inputArray = nullptr;
  size_t stringSize = 10;
  try
  {
    inputArray = shabalin::inputOfString(std::cin, stringSize);
    if ((inputArray[0] == '\n') || (inputArray[0] == '\0'))
    {
      delete[] inputArray;
      std::cerr << "Error" << "\n";
      return 1;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }


  std::cout << shabalin::duplicateNumbers(inputArray) << "\n";
  shabalin::makeLowerCaseString(inputArray);

  std::cout << inputArray << "\n";

  delete[] inputArray;
  return 0;
}
