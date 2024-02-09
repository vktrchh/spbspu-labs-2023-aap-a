#include <iostream>
#include "input_string.hpp"
#include "has_rep_symbol.hpp"
#include "has_rep_digit.hpp"

int main()
{
  using namespace ishmuratov;
  char * inArray = nullptr;
  try
  {
    inArray = inputString(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  std::cout << hasRep(inArray) << "\n";
  std::cout << hasRepDigit(inArray) << "\n";
  delete [] inArray;
  return 0;
}
