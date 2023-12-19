#include <iostream>
#include <string>

#include "mergeTwoLines.hpp"

int main()
{
  int num = 10;
  char* input = new char[num];
  size_t i = 0;

  char c = 0;
  while (std::cin >> c)
  {
    if (c == '\n')
    {
      input[i] = '\0';
      break;
    }
    input[i++] = c;

    if (i >= num)
    {
      num *= 2;
      char* symb = new char[num];
      for (int g = 0; g < i; ++g)
      {
        symb[g] = input[g];
      }
      delete[] input;
      input = symb;
    }
  }
  std::cout << input << "\n";
  delete[] input;

  std::string line1, line2;
  std::cout << "Enter the first line: ";
  std::getline(std::cin, line1);

  std::cout << "Enter the second line: ";
  std::getline(std::cin, line2);

  std::string merged = mergeTwoLines(line1, line2);
  std::cout << "Merged line: " << merged << '\n';
  return 0;
}
