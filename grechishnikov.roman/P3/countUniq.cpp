#include "countUniq.hpp"
#include <cctype>

size_t grechishnikov::countUniq(const char* str)
{
  size_t rez = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (isalpha(str[i]))
    {
      char del = str[i];
      int check = 1;
      for (int g = 0; g < i; g++)
      {
        if (del == str[g])
        {
          check = 0;
          break;
        }
      }
      if (check == 1)
      {
        rez++;
      }
    }
  }
  return rez;
}
