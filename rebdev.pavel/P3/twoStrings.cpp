#include "twoStrings.hpp"
#include <cctype>
#include <cstring>

char * rebdev::convertString(char * firstString, size_t firstSize, char * secondString, size_t secondSize)
{
  size_t numOfDig = 0;
  for (size_t i = 0; i < secondSize; ++i)
  {
    if (std::isdigit(secondString[i]))
    {
      numOfDig += 1;
    }
  }

  char * newStr = new char[firstSize + numOfDig + 1];
  
  size_t num = firstSize;

  for (size_t i = 0; i < num; ++i)
  {
    newStr[i] = firstString[i];
  }

  for (size_t i = 0; i < secondSize; ++i)
  {
    if (std::isdigit(secondString[i]))
    {
      newStr[num] = secondString[i];
      num += 1;
    }
  }
  newStr[firstSize + numOfDig] = '\0';

  return newStr;
}
