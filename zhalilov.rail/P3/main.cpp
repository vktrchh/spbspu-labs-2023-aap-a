#include <iostream>
#include <cstddef>

#include "inputString.hpp"
#include "findCommonestSymbs.hpp"
#include "countDiffSymbs.hpp"

int main()
{
  using namespace zhalilov;
  char *string = nullptr;
  size_t size = 0;
  try
  {
    string = new char[100];
    size = 100;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: " << e.what();
    return 1;
  }

  size_t endOfParse = 0;
  try
  {
    while (string[endOfParse] != '\0')
    {
      
    }
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
