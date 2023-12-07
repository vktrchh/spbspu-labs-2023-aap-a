#include <iostream>
#include <stdexcept>
#include "stringInput.hpp"
#include "twoStrings.hpp"


int main()
{
  char * firstStr = nullptr;
  char secondStr[] = {"Some123321 String 329408 with 3 number!"};
  using namespace rebdev;

  try
  {
    firstStr = inputStr(std::cin, firstStr);
    if ((firstStr == nullptr))
    {
      throw std::logic_error("Error message");
    }
  }
  catch (std::logic_error & e)
  {
    delete[] firstStr;
    return 1;
  }

  char * rez = stringConversion(firstStr, secondStr);
  std::cout << rez << '\n';
  delete[] rez;
  delete[] firstStr;
  return 0;
}
