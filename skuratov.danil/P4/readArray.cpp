#include "readArray.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>

int* skuratov::readArray(std::ifstream& in, int* array, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(in >> array[i]))
    {
      throw std::exception("Error reading element at index\n");
    }
    count++;
  }
  if (count != rows * cols)
  {
    throw std::exception("Error\n");
  }
  return array;
}
