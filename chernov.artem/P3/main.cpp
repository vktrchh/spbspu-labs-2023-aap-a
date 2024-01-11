#include "deleteDecimalDigits.hpp"
#include "removeVowels.hpp"

#include <iomanip>
#include <iostream>
#include <cstddef>

int main()
{
  using namespace chernov;
  size_t sizeOfInput = 20;
  char* input = new char[sizeOfInput]{};

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
    if (i < sizeOfInput)
    {
      input[i++] = c;
      if (c == '\n')
      {
        input[i - 1] = 0;
        break;
      }
    }
    else
    {
      sizeOfInput *= 2;
      char* oldInput = input;
      input = new char[sizeOfInput]{};
      for (size_t k = 0; k < i; k++)
      {
        input[k] = oldInput[k];
      }
      input[i++] = c;
      if (c == '\n')
      {
        input[i - 1] = 0;
        break;
      }
    }
  }
  std::cin >> std::skipws;
  char* stringWithDecimalDigitsRemoved = new char[sizeOfInput] {};
  char* stringWithVowelsRemoved = new char[sizeOfInput] {};

  char* withoutDecimalDigits = removeDecimalDigits(input, stringWithDecimalDigitsRemoved, sizeOfInput);
  char* withoutVowels = removeVowels(input, stringWithVowelsRemoved, sizeOfInput);

  std::cout << withoutDecimalDigits << "\n";
  std::cout << withoutVowels << "\n";

  delete[] stringWithDecimalDigitsRemoved;
  delete[] stringWithVowelsRemoved;
  delete[] input;
}
