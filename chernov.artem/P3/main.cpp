#include "deleteDecimalDigits.hpp"
#include "deleteVowels.hpp"

#include <iomanip>
#include <iostream>
#include <cstddef>

int main()
{
  using namespace chernov;
  size_t sizeOfInput = 20;
  char* input = new char[sizeOfInput] {};

  char c = 0;
  size_t i = 0;

  std::cin >> std::noskipws;

  while (std::cin >> c)
  {
    if (!std::cin)
    {
      std::cerr << "Error input\n";
      delete[] input;
      return 1;
    }
    if (i < sizeOfInput)
    {
      input[i++] = c;
      if (c == '\n')
      {
        if (i == 1)
        {
          std::cerr << "Empty string\n";
          delete[] input;
          return 1;
        }
        input[i - 1] = 0;
        break;
      }
    }
    else
    {
      char* oldInput = new char[sizeOfInput];
      sizeOfInput *= 2;

      for (size_t k = 0; k < i; ++k)
      {
        oldInput[k] = input[k];
      }

      delete[] input;
      input = new char[sizeOfInput];

      for (size_t k = 0; k < i; k++)
      {
        input[k] = oldInput[k];
      }

      input[i++] = c;
      if (c == '\n')
      {
        if (i == 1)
        {
          std::cerr << "Empty string\n";
          delete[] input;
          delete[] oldInput;
          return 1;
        }
        input[i - 1] = 0;
        break;
      }
      delete[] oldInput;
    }
  }

  char* stringWithDecimalDigitsRemoved = new char[sizeOfInput] {};
  char* stringWithVowelsRemoved = new char[sizeOfInput] {};

  char* withoutDecimalDigits = removeDecimalDigits(input, stringWithDecimalDigitsRemoved, sizeOfInput);
  char* withoutVowels = removeVowels(input, stringWithVowelsRemoved, sizeOfInput);

  std::cout << withoutDecimalDigits << "\n";
  std::cout << withoutVowels << "\n";

  delete[] stringWithDecimalDigitsRemoved;
  delete[] stringWithVowelsRemoved;
  delete[] input;
  return 0;
}
