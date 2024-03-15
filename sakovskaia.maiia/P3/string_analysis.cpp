#include "string_analysis.hpp"

int sakovskaia::checkRep(const char * const string)
{
  size_t i = 0;
  size_t j = 0;
  for (i = 0; string[i] != '\n'; i++)
  {
    for (j = 0; string[j] != '\n'; j++)
    {
      if ((string[i] == string[j]) && (i != j))
      {
        return 1;
      }
    }
  }
  return 0;
}
