#include "CountUniqueLetters.hpp"
#include <cctype>

size_t vyzhanov::countUniqueLetters(const char* string)
{
  size_t count = 0;
  for (size_t i = 0; string[i] != '\0'; ++i)
  {
    if (std::isalpha(string[i]))
    {
      int check = 1;
      char symb = string[i];
      size_t j = 0;
      for (j = 0; j < i; ++j)
      {
        if (symb == string[j])
        {
          check = 0;
          break;
        }
      }
      if (check == 1)
      {
        count++;
      }
    }
  }
  return count;
}
