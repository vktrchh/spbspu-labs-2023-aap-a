#include <iostream>
#include <string>
//#include "rectangle.hpp"
//#include "base-types.hpp"
#include "inputString.hpp"
int checkString(const char * string, const char * strForCheck)
{
  size_t i = 0;
  int checkFlag = 1;
  while (strForCheck[i] != '\0')
  {
    if (strForCheck[i] != string[i])
    {
      checkFlag = 0;
    }
    i++;
  }
  return checkFlag;
}

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  size_t capacity = 10;
  size_t length = 0;
  while (std::cin)
  {
    try
    {
    currDesc = inputString(std::cin, length, capacity);
    }
    catch(const char * errMessage)
    {
      std::cerr << errMessage << "\n";
      return 1;
    }
    std::cout << currDesc << "\n";
    if (checkString(currDesc, scaleStr) == 1)
    {
      break;
    }
  }
}
