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
      size_t j = 0;
      for (j = 0; j < i; ++j)
      {
        if (string[i] == string[j])
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
