#include "inputArray.hpp"
#include "replaceStringToLow.hpp"
#include "removeVowels.hpp"
#include <iostream>

int main()
{
  using namespace stepanov;
  char* newString = nullptr;
  size_t sizeString = 20;
  char* resultString = inputArray(std::cin, sizeString);
  try
  {
    newString = new char[sizeString] {};
    for (size_t i = 0; resultString[i] != '\0'; ++i)
    {
      newString[i] = resultString[i];
    }
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory:" << e.what() << '\n';
    return 1;
  }
  if (resultString[0] == '\0')
  {
    std::cerr << "Empty string" << '\n';
    delete[] resultString;
    delete[] newString;
    return 1;
  }
  std::cout << "String: " << resultString << '\n';
  char* resultRemoveVowels = removeVowels(newString);
  std::cout << "[RMV-VOW]: " << resultRemoveVowels << '\n';
  char* resultUpToLow = replaceStringToLow(resultString);
  std::cout << "[UPP-LOW]: " << resultUpToLow << '\n';
  delete[] resultString;
  delete[] newString;
}


