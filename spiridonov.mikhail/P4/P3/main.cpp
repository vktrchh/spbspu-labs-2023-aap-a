#include "seqsym.hpp"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace spiridonov;

int main()
{
  const size_t max_size = 100;
  char str[max_size];
  try
  {
    std::cout << "Enter a string: ";
    std::cin.getline(str, max_size);
  }

  catch (const char* error)
  {
    std::cerr << error << "\n";
    return 1;
  }
  char array[] = { 0 };

  size_t result = spiridonov::hasConsecutiveDuplicates(str);

  try
  {
    if (result == 1)
    {
      std::cout << "Array has consecutive duplicates\n";
    }
    else
    {
      std::cout << "Array does not have consecutive duplicates\n";
    }
  }
  catch (const char* error)
  {
    std::cerr << error << "\n";
    delete[] str;
    return 1;
  }

  std::cout << "Result: " << spiridonov::hasConsecutiveDuplicates(str) << "\n";
  return 0;
}
