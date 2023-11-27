#include "seqsym.hpp"

namespace spiridonov
{
  size_t spiridonov::hasConsecutiveDuplicates(const size_t* array, const size_t size)
  {
    for (size_t i = 1; i < size; i++)
    {
      if (array[i] == array[i - 1])
      {
        return 1;
      }
    }
    return 0;
  }
}
