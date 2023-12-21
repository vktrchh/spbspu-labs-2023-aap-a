#include <iostream>

#include "inputString.hpp"
#include "findCommonestSymbs.hpp"
#include "countDiffSymbs.hpp"

int main()
{
  using namespace zhalilov;
  char *string = nullptr;
  size_t lastIndex = 0;
  size_t size = 0;
  string = inputString(lastIndex, size, std::cin);
  if (lastIndex == 0)
  {
    std::cerr << "Invalid input\n";
    delete[] string;
    return 1;
  }
  else if (string[lastIndex] != '\0')
  {
    std::cerr << "Can't allocate memory for input\n";
    delete[] string;
    return 1;
  }
  char result[4] = "aaa";
  findCmnstSymbs(result, string);
  unsigned int diffSymbs = countDiffSymbs(string);
  std::cout << result << "\n";
  std::cout << diffSymbs << "\n";
  delete[] string;
}
