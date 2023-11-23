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
    result = new char[3];
    for (int i = 0; i < 3; i++)
    {
      result[i] = 0;
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: " << e.what();
    delete[] string;
    return 1;
  }
  result = comnstSymbs(result, string);
  std::cout << result << "\n";
}
