#include "taskOne.hpp"
#include <cctype>

size_t arakelyanTaskOne::countOfdifferentLetters(const char *myArray)
{
  size_t count = 0;
  for (size_t i = 'a'; i <= 'z'; i++)
  {
    for (size_t j = 0; myArray[j] != '\0'; j++)
    {
      unsigned char symb = std::tolower(myArray[j]);
      if (std::isalpha(symb) && (symb == i))
      {
        count++;
        break;
      }
    }
  }

  return count;
}
