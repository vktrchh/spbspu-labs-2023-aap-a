#include "mergeTwoLines.h"
#include "removeDuplicate.h"

#include <cstddef>
#include <iostream>
#include <stdexcept>

int main()
{
  using namespace skuratov;
  size_t size = 10;
  char* inputLine = new char[size]{};
  const char* lineOfProgram = "abc";

  char c = 0;
  size_t i = 0;

  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    if (!std::cin)
    {
      std::cerr << "Error input\n";
      return 1;
    }
    if (i < size)
    {
      inputLine[i++] = c;
      if (c == '\n')
      {
        inputLine[i - 1] = 0;
        break;
      }
    }
    else
    {
      size *= 2;
      char* oldInput = inputLine;
      inputLine = new char[size]{};
      for (size_t m = 0; m < i; m++)
      {
        inputLine[m] = oldInput[m];
      }
      inputLine[i++] = c;
      if (c == '\n')
      {
        inputLine[i - 1] = 0;
        break;
      }
    }
  }
  char* mergedStrings = new char[size] {};
  char* stringWithRemovedDuplicates = new char[size] {};
  std::cout << mergeTwoLines(mergedStrings, inputLine, lineOfProgram) << '\n';
  std::cout << removeDuplicate(stringWithRemovedDuplicates, lineOfProgram, inputLine, 3, size);
  delete[] inputLine;
  delete[] mergedStrings;
  delete[] stringWithRemovedDuplicates;
}
