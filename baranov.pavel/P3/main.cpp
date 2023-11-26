#include <iostream>
#include "inputString.hpp"
#include "deleteDigits.hpp"

int main()
{
  char * string = nullptr;
  size_t size = 0;
  try
  {
    string = inputString(std::cin, size);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 2;
  }

  char * result = nullptr;
  try
  {
    result = new char[size];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] string;
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  deleteDigits(string, size, result);
  std::cout << result << '\n';

  delete[] string;
  delete[] result;
}

