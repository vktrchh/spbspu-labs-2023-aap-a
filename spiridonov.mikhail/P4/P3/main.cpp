#include "seqsym.hpp"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace spiridonov;

int main()
{
  const int max_size = 100;
  char str[max_size];

  std::cout << "Enter a string: ";
  std::cin.getline(str, max_size);

  int result = spiridonov::hasConsecutiveDuplicates(str);

  std::cout << "Result: " << result << "\n";

  return 0;
}
