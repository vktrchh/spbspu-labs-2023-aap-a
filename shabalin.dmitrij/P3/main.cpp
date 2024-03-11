#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

int main()
{
  using namespace shabalin;
  char *finalyString = nullptr;
  size_t stringSize = 50;
  char *temporaryString = nullptr;
  try
  {
    finalyString = inputOfString(std::cin, stringSize);
    char *temporaryString = new char[stringSize];
  }
  catch (std::exception & e)
  {
    delete[] finalyString;
    delete[] temporaryString;
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  if (finalyString[0] == '\0')
  {
    delete[] temporaryString;
    delete[] finalyString;
    std::cerr << "Error" << "\n";
    return 1;
  }

  size_t answer = duplicateNumbers(finalyString);
  std::cout << answer << "\n";

  char result[] = "123";
  makeLowerCaseString(finalyString, result);
  std::cout << result;

  delete[] finalyString;
  delete[] temporaryString;
  return 0;
}
