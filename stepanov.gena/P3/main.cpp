#include "inputArray.hpp"
#include <iostream>

int main()
{
  using namespace stepanov;
  char* resultString = inputArray(std::cin);
  std::cout << resultString << '\n';
  delete[] resultString;
}



