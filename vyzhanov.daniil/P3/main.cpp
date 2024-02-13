#include <iostream>
#include "InputString.hpp"

int main()
{
  using namespace vyzhanov;
  char* string = nullptr;
  try
  {
    string = inputString(std::cin);
    std::cout << string << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
}
