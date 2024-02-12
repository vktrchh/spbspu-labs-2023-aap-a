#include "copyNum.hpp"
#include <cctype>
#include <cstddef>

void sivkov::copyNum(char* string1, const char* string2)
{
  size_t length1 = 0;
  while (string1[length1] != '\0')
  {
    ++length1;
  }

  size_t index1 = length1;
  size_t index2 = 0;
  while (string2[index2] != '\0')
  {
    if (std::isdigit(string2[index2]))
    {
      string1[index1] = string2[index2];
      ++index1;
    }
    ++index2;
  }

  string1[index1] = '\0';
}

