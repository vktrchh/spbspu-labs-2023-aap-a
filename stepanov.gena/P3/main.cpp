#include "inputArray.hpp"
#include "replaceStringToLow.hpp"
#include "removeVowels.hpp"
#include <iostream>

int main()
{
  using namespace stepanov;
  size_t sizeString = 20;
  char* resultString = inputArray(std::cin, sizeString);
  if (resultString[0] == '\0')
  {
    std::cerr << "Empty string" << '\n';
    delete[] resultString;
    return 1;
  }
  std::cout << "String: " << resultString << '\n';
  char* resultRemoveVowels = removeVowels(resultString);
  std::cout << "[RMV-VOW]: " << resultRemoveVowels << '\n';
  char* resultUpToLow = replaceStringToLow(resultString);
  std::cout << "[UPP-LOW]: " << resultUpToLow << '\n';
  delete[] resultString;
}


