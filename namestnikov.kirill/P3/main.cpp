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
    return 1;
  }
  size_t firstSize = getSizeOfString(firstString);
  if ((firstString[0] == '\0') || (!firstString))
  {
    std::cerr << "No string input\n";
    delete [] firstString;
    return 1;
  }
  const char * secondString = "abc_ef";
  size_t secondSize = 6;
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
    return 1;
  }
  size_t length = getSizeOfString(result);
  std::sort(result, result + length);
  std::cout << result << "\n";
  delete [] firstString;
  delete [] result;
}
