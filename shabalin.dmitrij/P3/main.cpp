/*
#include <iostream>
#include <stdexcept>
#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

int main()
{
  using namespace shabalin;
  char *finalString = nullptr;
  char *initialString = nullptr;
  size_t initialSize = 50;
  try
  {
    finalString = inputOfString(std::cin, initialString, initialSize);
    if (finalString[0] == '\0')
    {
      delete[] finalString;
      std::cerr << "Error" << "\n";
      return 1;
    }
    std::cout << duplicateNumbers(finalString) << "\n";
    char result[] = "123";
    std::cout << makeLowerCaseString(finalString, result) << "\n";
  }
  catch (const std::bad_alloc &e)
  {
    delete[] finalString;
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  delete[] finalString;
  return 0;
}


#include <iostream>
#include <stdexcept>
#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

int main()
{
  using namespace shabalin;
  char *initialString = nullptr;
  // size_t initialSize = 10;

  try
  {
    initialString = inputOfString(std::cin);
    if (initialString[0] == '\0')
    {
      std::cerr << "Error\n";
      delete[] initialString;
      return 1;
    }
    std::cout << duplicateNumbers(initialString) << "\n";
    char result[] = "123";
    std::cout << makeLowerCaseString(initialString, result) << "\n";
    delete[] initialString;
    return 0;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    delete[] initialString;
    return 1;
  }
}


#include <iostream>
#include <stdexcept>
#include "duplicateNumbers.h"
#include "makeLowerCaseString.h"
#include "inputOfString.h"

int main()
{
  using namespace shabalin;
  char *initialString = nullptr;
  //size_t initialSize = 10;
  try
  {
    initialString = inputOfString(std::cin);
    bool isOnlySpace = false;
    for (size_t j = 0; initialString[j] != '\0'; ++j)
    {
      if (!std::isspace(initialString[j]))
      {
        isOnlySpace = true;
        break;
      }
    }

    if (!isOnlySpace)
    {
      delete[] initialString;
      throw std::invalid_argument("Empty input");
    }

    if (initialString[0] == '\0')
    {
      delete[] initialString;
      std::cerr << "Empty input\n";
      return 1;
    }
    std::cout << duplicateNumbers(initialString) << "\n";
    //size_t resultSize = initialSize;
    //char *result = new char[resultSize];
    char result[] = "31232";
    std::cout << makeLowerCaseString(initialString, result) << "\n";

    //delete[] result;
    delete[] initialString;
    return 0;
  }
  catch (const std::exception &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
*/

#include <iostream>
#include <stdexcept>
#include "duplicateNumbers.h"
#include "inputOfString.h"
#include "makeLowerCaseString.h"

int main()
{
  using namespace shabalin;
  char* inputArray = nullptr;
  const size_t numberOfChars = 128;

  try
  {
    inputArray = inputOfString(std::cin);
    std::cout << inputArray;
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }

  std::cout << duplicateNumbers(inputArray) << "\n";

  char result[] = "abc";
  makeLowerCaseString(inputArray, result);

  std::cout << result << "\n";

  delete[] inputArray;
  return 0;
}