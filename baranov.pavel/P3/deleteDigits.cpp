#include "deleteDigits.hpp"
#include <cctype>

void deleteDigits(const char * string, const size_t size, char * result)
{
  size_t j = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (!std::isdigit(string[i]))
    {
      result[j] = string[i];
      ++j;
    }
  }
}

