#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

int main()
{
  using namespace shabalin;
  char *finalyString = nullptr;

  try
  {
    finalyString = inputOfString(std::cin);
  }
  catch (std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    delete[] finalyString;
    return 1;
  }

  if (finalyString[0] == '\0')
  {
    delete[] finalyString;
    std::cerr << "Error";
    return 1;
  }
  size_t answer = duplicateNumbers(finalyString);
  std::cout << answer << "\n";

  char result[] = "123";
  makeLowerCaseString(finalyString, result);
  std::cout << result;

  return 0;
}
