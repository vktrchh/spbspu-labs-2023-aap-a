#include "readArray.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>

int* readArray(std::istream& in, int* array, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(in >> array[i]))
    {
      throw std::runtime_error("Error reading element at index");
    }
    count++;
  }
  if (count != rows * cols)
  {
    throw std::runtime_error("Error");
  }
  return array;
}
