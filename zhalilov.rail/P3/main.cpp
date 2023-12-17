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
    std::cerr << "Error: " << e.what();
    return 1;
  }
  if (!string)
  {
    std::cerr << "Invalid input\n";
    return 1;
  }
  char *result = nullptr;
  try
  {
    result = new char[4]{};
  }
  catch (const std::bad_alloc &e)
  {
    delete[] string;
    std::cerr << "Error: " << e.what();
    return 1;
  }
  findCmnstSymbs(result, string);
  unsigned int diffSymbs = countDiffSymbs(string);
  std::cout << result << "\n";
  std::cout << diffSymbs << "\n";
  delete[] string;
  delete[] result;
}
