#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "stringInput.hpp"
#include "twoStrings.hpp"


int main()
{
  char * firstStr = nullptr;
  char secondStr[] = {"12 ok 35 z 3 pv21"};
  
  try
  {
    firstStr = rebdev::acceptStr(std::cin);
  }
  catch (std::logic_error & e)
  {
    delete[] firstStr;
    return 1;
  }
  if (firstStr == nullptr)
  {
    return 1;
  }
  
  char * rez = rebdev::convertString(firstStr, strlen(firstStr), secondStr, strlen(secondStr));
  
  std::cout << rez << '\n';
  delete[] rez;
  delete[] firstStr;

  return 0;
}
