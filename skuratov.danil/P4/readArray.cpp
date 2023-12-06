#include "readArray.h"
#include <fstream>
#include <stdexcept>

int* readArray(std::ifstream& in, int array[], const size_t& rows, const size_t& cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      in >> array[i * cols + j];
      if (!in)
      {
        throw std::runtime_error("Invalid input array from file");
      }
    }
  }
  return array;
}
