#include <iostream>
#include "InputString.hpp"
#include "DeleteAllNumbers.hpp"

int main()
{
  using namespace vyzhanov;
  char* string = nullptr;
  char* newString = nullptr;
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
    std::cerr << "Empty string!" << "\n";
    return 1;
  }
  size_t stringLength = 0;

  while (string[stringLength])
  {
    stringLength++;
  }

  try
  {
    newString = new char[stringLength];
    std::cout << vyzhanov::deleteAllNumbers(string, newString, stringLength) << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error";
    delete[] string;
    delete[] newString;
    return 1;
  }
  delete[] string;
  delete[] newString;
}
