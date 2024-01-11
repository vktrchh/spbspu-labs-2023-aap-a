#include "matrix.hpp"
#include <iostream>

void sivkov::fillMatrix(std::istream& input, int* m, size_t size)
{
  size_t count = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (!(input >> m[i]))
    {
      throw std::logic_error("Cannot read numbers\n");
    }
    count++;
  }
  if (count != size)
  {
    m = nullptr;
  }
}
