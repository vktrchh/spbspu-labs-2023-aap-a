#include <iostream>
#include "input_array.hpp"
#include "check_matches.hpp"

int main()
{
  char* firstArray = nullptr;
  char* secondArray = nullptr;

  using namespace nikitov;
  std::pair <char*, size_t> firstPair = inputArray(firstArray);
  std::pair <char*, size_t> secondPair = inputArray(secondArray);

  firstArray = firstPair.first;
  secondArray = secondPair.first;
  size_t firstSize = firstPair.second;
  size_t secondSize = secondPair.second;

  std::cout << checkMatches(firstArray, secondArray, firstSize, secondSize) << '\n';
  delete [] firstArray;
  delete [] secondArray;

  return 0;
}
