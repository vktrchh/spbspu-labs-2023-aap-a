#include <iostream>
#include "InputString.hpp"
#include "DeleteAllNumbers.hpp"

int main()
{
  using namespace vyzhanov;
  char* string = nullptr;
  try
  {
    string = inputString(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  try
  {
    std::cout << vyzhanov::deleteAllNumbers(string) << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error";
    return 1;
  }
}
