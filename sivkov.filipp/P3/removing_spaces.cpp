#include "removing_spaces.hpp"
#include <cctype>

char* deleteSpace(char* string)
{
  if (string == nullptr)
  {
    return nullptr;
  }

  size_t length = 0;
  while (string[length] != '\0')
  {
    ++length;
  }

  size_t startIndex = 0;
  while (std::isspace(string[startIndex]))
  {
    ++startIndex;
  }

  size_t newLength = length - startIndex;

  char* arrayWithOutSpace = new char[newLength + 1];
  size_t indexArr = 0;

  for (size_t j = startIndex; j < length; ++j)
  {
    if (std::isspace(string[j]))
    {
      if (indexArr == 0 || arrayWithOutSpace[indexArr - 1] != ' ')
      {
        arrayWithOutSpace[indexArr++] = ' ';
      }
    }
    else
    {
      arrayWithOutSpace[indexArr++] = string[j];
    }
  }

  arrayWithOutSpace[indexArr] = '\0';
  return arrayWithOutSpace;
}
