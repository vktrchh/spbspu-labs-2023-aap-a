#include <iostream>
#include "input_array.hpp"
#include "check_matches.hpp"

int main()
{
  char* firstArray = nullptr;

  using namespace nikitov;
  std::pair <char*, size_t> firstPair{};
  try
  {
    firstPair = inputArray(firstArray);
  }
  catch(const char* errorMessage)
  {
    std::cerr << errorMessage << '\n';
    return 1;
  }

  firstArray = firstPair.first;
  size_t firstSize = firstPair.second;

  if (firstArray[0] == '\0')
  {
    std::cerr << "Error: Empty input\n";
    delete [] firstArray;
    return 1;
  }
  const char* secondArray = "abc";
  size_t secondSize = 3;

  std::cout << checkMatches(firstArray, secondArray, firstSize, secondSize) << '\n';
  delete [] firstArray;

  return 0;
}
