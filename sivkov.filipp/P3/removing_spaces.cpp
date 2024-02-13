#include <cctype>
#include <string>
#include "removing_spaces.hpp"

void sivkov::deleteSpace(char* string)
{
  if (string == nullptr)
  {
    return;
  }

  char* writePtr = string;
  char* readPtr = string;
  bool previousWasSpace = false;

  while (std::isspace(*readPtr))
  {
    ++readPtr;
  }

  while (*readPtr != '\0')
  {
    if (!std::isspace(*readPtr))
    {
      *writePtr = *readPtr;
      ++writePtr;
      previousWasSpace = false;
    }
    else if (!previousWasSpace)
    {
      *writePtr = ' ';
      ++writePtr;
      previousWasSpace = true;
    }
    ++readPtr;
  }
  *writePtr = '\0';
}
