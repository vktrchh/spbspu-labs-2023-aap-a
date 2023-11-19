#include <iostream>
#include <iomanip>
#include <cstring>
#include "input_array.hpp"

int main()
{
  char* firstArray = nullptr;
  char* secondArray = nullptr;

  std::pair <char*, size_t> firstPair = inputArray(firstArray);
  std::pair <char*, size_t> secondPair = inputArray(secondArray);

  firstArray = firstPair.first;
  secondArray = secondPair.first;
  size_t firstSize = firstPair.second;
  size_t secondSize = secondPair.second;
  std::cout << firstArray << '\n';
  std::cout << firstSize << '\n';
  std::cout << secondArray << '\n';
  std::cout << secondSize << '\n';
  delete [] firstArray;
  delete [] secondArray;

  return 0;
}
