#include "transformInputString.hpp"
#include <iostream>
#include <iomanip>

char* skuratov::transformInputString(char* input, size_t size)
{
  char c = 0;
  size_t i = 0;
 
  try
  {
    std::cin >> std::noskipws;
    while (std::cin >> c)
    {
      if (i == 0 && c == '\n')
      {
        throw std::runtime_error("Error input");
      }
      if (i == size - 1)
      {
        size += 10;
        char* newInput = new char[size];
        for (size_t j = 0; j < i; j++)
        {
          newInput[j] = input[j];
        }
        delete[] input;
        input = newInput;
      }
      input[i] = c;
      i++;
      if (c == '\n')
      {
        input[i - 1] = '\0';
        break;
      }
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return nullptr;
    delete[] input;
  }
  return input;
}
