#include "inputMatrix.hpp"
#include <algorithm>

size_t inputArray(std::istream & in, int * array, size_t size, size_t toread)
{
  for (size_t i = 0; i < std::min(size, toread); ++i)
  {
    in >> array[i];
    if (!in)
    {
      return i;
    }
  }
  return std::min(size, toread);
}
