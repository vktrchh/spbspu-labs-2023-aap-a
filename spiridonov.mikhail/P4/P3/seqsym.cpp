#include "seqsym.hpp"

using namespace spiridonov;

int spiridonov::hasConsecutiveDuplicates(const char* str)
{
  int length = strlen(str);
  for (int i = 1; i < length; i++)
  {
    if (str[i] == str[i - 1])
    {
      return 1;
    }
  }

  return 0;
}
