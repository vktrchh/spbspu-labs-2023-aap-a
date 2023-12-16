#include <iostream>
#include <iomanip>
#include <algorithm>
#include "unique_sym_array.hpp"
#include "input_string.hpp"

int main()
{
  using namespace namestnikov;
  char * firstString = nullptr;
  try
  {
    firstString = inputString(std::cin);
  }
  catch (...)
  {
    std::cerr << "Not enough memory\n";
    return 2;
  }
  size_t firstSize = getSizeOfString(firstString);
  if ((!firstString) || (firstSize == 0))
  {
    std::cerr << "No string input\n";
    return 2;
  }
  const char * secondString = "bc_fu";
  size_t secondSize = 5;
  char * result = nullptr;
  try
  {
    result = new char[std::min(firstSize, secondSize)];
    getUniqueSymArray(result, firstString, secondString, firstSize, secondSize);
  }
  catch (const std::bad_alloc & e)
  {
    delete [] firstString;
    std::cerr << "Not enough memory\n";
    return 2;
  }
  size_t length = getSizeOfString(result);
  std::sort(result, result + length);
  std::cout << result << "\n";
  delete [] firstString;
  delete [] result;
}
