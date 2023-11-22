#include <iostream>

#include "inputString.hpp"
#include "commonestSymbs.hpp"

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

  char *result = nullptr;
  try
  {
    result = commonestSymbs(string);
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << "Error: " << e.what();
    delete[] string;
    return 1;
  }
  std::cout << result << "\n";
}
