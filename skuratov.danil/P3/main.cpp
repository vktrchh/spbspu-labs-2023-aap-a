#include <iostream>
#include <cstddef>
#include <stdexcept>

#include "mergeTwoLines.h"
#include "removeDuplicate.h"
#include "transformInputString.h"

int main()
{
  size_t size = 10;
  char* inputLine = new char[size];
  const char* lineOfProgram = "abc";
  try
  {
    inputLine = skuratov::transformInputString(inputLine, size);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    delete[] inputLine;
    return 1;
  }
  size_t size1 = 0;
  while (*inputLine != '\0')
  {
    size1++;
    inputLine++;
  }
  size_t size2 = 0;
  while (*lineOfProgram != '\0')
  {
    size2++;
    lineOfProgram++;
  }
  size_t c = size1;
  size_t c2 = size2;

  while (c > 0)
  {
    inputLine--;
    c--;
  }
  while (c2 > 0)
  {
    lineOfProgram--;
    c2--;
  }
  size_t size3 = size1 + size2;
  char* result = new char[size3 + 1];
  std::cout << skuratov::mergeTwoLines(result, inputLine, lineOfProgram) << '\n';
  std::cout << skuratov::removeDuplicate(result, lineOfProgram, inputLine, size1, size2) << '\n';
  delete[] result;
  delete[] inputLine;
}
