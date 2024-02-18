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
  if (string[0] == '\0')
  {
    delete[] string;
    std::cerr << "Error: Empty string!" << "\n";
    return 1;
  }
  try
  {
    std::cout << vyzhanov::deleteAllNumbers(string) << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error";
    delete[] newString;
    return 1;
  }
  delete[] newString;
  delete[] string;
  return 0;
}
