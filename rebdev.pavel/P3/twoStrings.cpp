#include "twoStrings.hpp"
#include <cctype>
#include <cstring>
#include <cstddef>

char * rebdev::stringConversion(char * firstString, char * secondString)
{
  size_t numOfDig = 0;
  for (size_t i = 0; i < std::strlen(secondString); ++i)
  {
    if (std::isdigit(secondString[i]))
    {
      numOfDig+=1;
    }
  }
   
  char * newStr = new char[std::strlen(firstString) + numOfDig];
  
  for (size_t i = 0; i < std::strlen(firstString) - 1; ++i)
  {
    newStr[i] = firstString[i];
  }

  size_t num = std::strlen(firstString) - 1;

  for (size_t i = 0; i < std::strlen(secondString); ++i)
  {
    if (std::isdigit(secondString[i]))
    {
      newStr[num] = secondString[i];
      num+=1;
    }
  }

  return newStr;
}
