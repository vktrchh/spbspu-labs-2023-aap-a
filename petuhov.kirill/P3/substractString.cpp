#include "substractString.hpp"

char * petuhov::substractString(const char * firstString, size_t firstStringSize, const char * secondString)
{
  if (firstStringSize == 0)
  {
    throw std::logic_error("First string size is under or equal 0");
  }

  if (firstString == nullptr || secondString == nullptr)
  {
    throw std::logic_error("String cannot be nullptr");
  }
  
  char * result = new char[firstStringSize];
  size_t resultIndex = 0;

  for (int i = 0; firstString[i] != '\0'; ++i)
  {
    bool charFound = false;

    for (int j = 0; secondString[j] != '\0'; ++j)
    {
      if (firstString[i] == secondString[j])
      {
        charFound = true;
        break;
      }
    }

    if (!charFound)
    {
      result[resultIndex++] = firstString[i];
    }
  }
  result[resultIndex] = '\0';
  return result;
}
