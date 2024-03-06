#include "output.h"
#include <fstream>

void skopchenko::intOutput(std::ostream &oFile, int *matrix, size_t rows, size_t cols)
{
  if (!(oFile << rows << ' ' << cols))
  {
    throw std::logic_error("Error during output:/");
  }
  oFile << std::fixed;
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(oFile << ' ' << matrix[i]))
    {
      throw std::logic_error("Couldnt output");
    }
  }
}

void skopchenko::doubleOutput(std::ostream &oFile, const double *matrix, size_t rows, size_t cols)
{
  if (!(oFile << rows << ' ' << cols))
  {
    throw std::logic_error("Error during output:/");
  }
  oFile << std::fixed << std::setprecision(1);
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(oFile << ' ' << matrix[i]))
    {
      throw std::logic_error("Couldnt output");
    }
  }
}
