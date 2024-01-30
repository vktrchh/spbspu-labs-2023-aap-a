#include "transformInputString.hpp"
#include <iostream>
#include <iomanip>

char* skuratov::transformInputString(char* input, size_t size)
{
  char c = 0;
  size_t i = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    if (i == 0 && c == '\n')
    {
      std::cerr << "Error input";
      return nullptr;
    }
    if (i == size - 1)
    {
      size += 10;
      char* newinput = new char[size];
      for (size_t j = 0; j < i; j++)
      {
        newinput[j] = input[j];
      }
      delete[] input;
      input = newinput;
    }
    input[i] = c;
    i++;
    if (c == '\n')
    {
      input[i - 1] = '\0';
      break;
    }
  }
  return input;
}
