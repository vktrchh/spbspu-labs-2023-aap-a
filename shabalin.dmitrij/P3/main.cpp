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
  catch (std::bad_alloc & e)
  {
    delete[] finalyString;
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  if (finalyString[0] == '\0')
  {
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
  return 0;
}
