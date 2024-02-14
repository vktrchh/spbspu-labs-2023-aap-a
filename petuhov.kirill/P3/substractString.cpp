#include "substractString.hpp"

void petuhov::substractString(char * firstString, size_t firstStringSize, const char * secondString)
{
  size_t resultIndex = 0;

  for (int i = 0; firstString[i] != '\0'; ++i)
  {
    bool charFound = 0;

    for (int j = 0; secondString[j] != '\0'; ++j)
    {
      if (firstString[i] == secondString[j])
      {
        charFound = 1;
        break;
      }
    }

    if (!charFound)
    {
      firstString[resultIndex++] = firstString[i];
    }
  }
  firstString[resultIndex] = '\0';
}
