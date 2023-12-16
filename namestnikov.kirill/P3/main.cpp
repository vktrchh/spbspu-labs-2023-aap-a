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
  try
  {
    constexpr size_t defaultSize = 20;
    result = new char[defaultSize];
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
