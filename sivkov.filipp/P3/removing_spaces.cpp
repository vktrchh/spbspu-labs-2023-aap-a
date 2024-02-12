#include "removing_spaces.hpp"
#include <cctype>
#include <string>

void sivkov::deleteSpace(char* string)
{
  if (string == nullptr)
  {
    return;
  }

  size_t writeIndex = 0;


  size_t readIndex = 0;
  while (std::isspace(string[readIndex]))
  {
    ++readIndex;
  }

  bool previousWasSpace = false;
  while (string[readIndex] != '\0')
  {
    if (!std::isspace(string[readIndex]))
    {
      string[writeIndex] = string[readIndex];
      ++writeIndex;
      previousWasSpace = false;
    }
    else if (!previousWasSpace)
    {
      string[writeIndex] = ' ';
      ++writeIndex;
      previousWasSpace = true;
    }
    ++readIndex;
  }

  string[writeIndex] = '\0';
}

