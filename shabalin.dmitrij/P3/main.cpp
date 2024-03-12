/*


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
  std::cout << duplicateNumbers(finalyString) << "\n";

  char result[] = "123";
  makeLowerCaseString(finalyString, result);
  std::cout << result;

  return 0;
}
*/

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
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  if (finalString[0] == '\0')
  {
    delete[] finalString;
    std::cerr << "Error: Empty string!" << "\n";
    return 1;
  }
  std::cout << duplicateNumbers(finalString) << "\n";
  char result[] = "123";
  std::cout << makeLowerCaseString(finalString, result) << "\n";
  delete[] finalString;
  return 0;
}