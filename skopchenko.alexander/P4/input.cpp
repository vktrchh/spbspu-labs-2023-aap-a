#include "input.h"
#include <fstream>

void skopchenko::input(std::istream& iFile, int * matrix , size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; i++)
  {
    iFile >> matrix[i];
    if (!iFile)
    {
      throw std::logic_error("Bad input\n");
    }
  }
}
