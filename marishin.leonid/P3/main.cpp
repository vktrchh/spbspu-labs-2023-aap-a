#include <iostream>

#include "inputstring.hpp"
#include "modifystring.hpp"

int main()
{
  using namespace marishin;
  std::cin >> std::noskipws;
  char* buffer = nullptr;
  char firstSymbol = 'c';
  char secondSymbol = 'b';
  try
  {
    buffer = inputString(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  std::cin >> std::skipws;
  try
  {
    buffer = modifyString(buffer, firstSymbol, secondSymbol);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  std::cout << buffer;
  delete[] buffer;
}
