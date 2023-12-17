#include <iostream>
#include <iomanip>
#include <algorithm>
#include "unique_sym_array.hpp"
#include "input_string.hpp"

int main()
{
  using namespace namestnikov;
  char * firstString = nullptr;
  size_t strIndex = 0;
  try
  {
    firstString = inputString(std::cin, strIndex);
  }
  catch (...)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  if ((firstString[0] == '\0') || (!firstString))
  {
    std::cerr << "No string input\n";
    delete [] firstString;
    return 1;
  }
  const char * secondString = "abc_ef";
  char * result = nullptr;
  size_t resultIndex = 0;
  size_t resultSize = 0;
  const size_t firstSize = strIndex;
  const size_t secondSize = 6;
  try
  {
    size_t defaultSize = std::max(firstSize, secondSize);
    result = new char[defaultSize]{};
    result[0] = '\0';
    resultSize = defaultSize;
    getUniqueSymArray(firstString, secondString, result, resultSize, resultIndex);
    getUniqueSymArray(secondString, firstString, result, resultSize, resultIndex);
  }
  catch (const std::bad_alloc & e)
  {
    delete [] firstString;
    std::cerr << "Not enough memory\n";
    return 1;
  }
  std::sort(result, result + resultIndex);
  std::cout << result << "\n";
  delete [] firstString;
  delete [] result;
}
