#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include "stringInput.hpp"
#include "stringConvert.hpp"


int main()
{
  char * firstStr = nullptr;

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
  
  const char * secondStr = "1 2ok 3 5z 3pv21";
  char * rez = rebdev::convertString(firstStr, strlen(firstStr), secondStr, strlen(secondStr));

  std::cout << rez << '\n';
  delete[] rez;
  delete[] firstStr;

  return 0;
}
