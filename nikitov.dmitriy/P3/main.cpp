#include <iostream>
#include <iomanip>
#include <cstring>
#include "input_array.hpp"

int main()
{
  char* firstArray = nullptr;
  char* secondArray = nullptr;

  firstArray = inputArray(firstArray);
  secondArray = inputArray(secondArray);
  std::cout << firstArray << '\n';
  std::cout << secondArray << '\n';
  delete [] firstArray;
  delete [] secondArray;

  return 0;
}
