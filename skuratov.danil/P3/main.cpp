#include "mergeTwoLines.h"
#include "removeDuplicate.h"
#include "transformInputString.h"

#include <cstddef>
#include <iostream>
#include <stdexcept>

int main()
{
  const size_t size = 10;
  char* inputLine = new char[size];
  std::fill(inputLine, inputLine + size, '\0');
  const char* lineOfProgram = "abc";

  try
  {
    inputLine = skuratov::transformInputString(inputLine, size);

    size_t size1 = 0;
    char* inputLinePtr = inputLine;
    while (*inputLinePtr != '\0')
    {
      size1++;
      inputLinePtr++;
    }

    size_t size2 = 0;
    while (*lineOfProgram != '\0')
    {
      size2++;
      lineOfProgram++;
    }

    inputLinePtr = inputLine;
    lineOfProgram -= size2;

    size_t size3 = size1 + size2;
    char* result = new char[size3 + 1];

    std::cout << skuratov::mergeTwoLines(result, inputLinePtr, lineOfProgram) << '\n';
    std::cout << skuratov::removeDuplicate(result, lineOfProgram, inputLinePtr, size1, size2) << '\n';

    delete[] result;
    delete[] inputLine;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    delete[] inputLine;
    return 1;
  }
  return 0;
}
