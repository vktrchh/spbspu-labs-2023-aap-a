#include "countUnic.hpp"

size_t countUnic(char* str, size_t len)
{
  size_t rez = 0;
  char unicLett[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  for (size_t i = 0; i < len; ++i)
  {
    for (size_t g = 0; g < 52; ++g)
    {
      if (str[i] == unicLett[g])
      {
        unicLett[g] = char(255);
        rez++;
      }
    }
  }
  return rez;
}
