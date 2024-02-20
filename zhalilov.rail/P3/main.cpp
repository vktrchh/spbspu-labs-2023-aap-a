#include <iostream>

#include "inputString.hpp"
#include "findCommonestSymbs.hpp"
#include "countDiffSymbs.hpp"

int main()
{
  using namespace zhalilov;
  char *string = nullptr;
  try
  {
    string = inputString(std::cin);
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << "Error: " << e.what();
    return 1;
  }
  catch (const std::invalid_argument &e)
  {
    std::cout << "Error: " << e.what();
    return 1;
  }
  char result[] = "aaa";
  findCmnstSymbs(result, string);
  unsigned int diffSymbs = countDiffSymbs(string);
  std::cout << result << "\n";
  std::cout << diffSymbs << "\n";
  delete[] string;
}
