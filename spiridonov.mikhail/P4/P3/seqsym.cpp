#include "seqsym.hpp"
#include <cstring>

using namespace spiridonov;

size_t spiridonov::hasConsecutiveDuplicates(const size_t* array, const size_t size)
{

  for (int i = 1; i < size; i++)
  {
    if (array[i] == array[i - 1])
    {
      return 1;
    }
  }

  return 0;
}
