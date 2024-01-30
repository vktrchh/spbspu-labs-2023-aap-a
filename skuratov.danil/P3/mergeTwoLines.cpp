#include "mergeTwoLines.hpp"

#include <cstddef>
#include "transformInputString.hpp"

char* skuratov::mergeTwoLines()
{
  size_t size = 10;

  char* input1 = new char[size];
  input1 = transformInputString(input1, size);

  char* input2 = new char[size];
  input2 = transformInputString(input2, size);

  size_t size1 = 0;
  while (*input1 != '\0')
  {
    size1++;
    input1++;
  }
  size_t size2 = 0;
  while (*input2 != '\0')
  {
    size2++;
    input2++;
  }
  size_t c = size1;
  size_t c2 = size2;
  while (c > 0)
  {
    input1--;
    c--;
  }
  while (c2 > 0)
  {
    input2--;
    c2--;
  }
  size_t size3 = size1 + size2;
  char* result = new char[size3 + 1];

  int i = 0;
  while (*input1 != '\0' || *input2 != '\0')
  {
    if (*input1 != '\0')
    {
      result[i] = *input1;
      i++;
      input1++;
    }
    if (*input2 != '\0')
    {
      result[i] = *input2;
      i++;
      input2++;
    }
  }
  result[i] = '\0';
  return result;
  delete[] input1;
  delete[] input2;
}
