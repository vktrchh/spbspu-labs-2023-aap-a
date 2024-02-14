#include "inputArray.hpp"
#include <iostream>

int main()
{
  using namespace stepanov;
  char* resultString = inputArray(std::cin);
  if (resultString[0] == '\0')
  {
    std::cerr << "Empty string" << '\n';
    return 1;
  }
  std::cout << resultString << '\n';
  delete[] resultString;
}



