#include "readArray.h"
#include <fstream>
#include <stdexcept>

int* readArray(std::ifstream& in, int array[], const size_t& size)
{
  for (size_t i = 0; i < size - 1; ++i)
  {
    in >> array[i];
    if (!in)
    {
       throw std::runtime_error("Invalid input file");
    }
  }
  return array;
}
