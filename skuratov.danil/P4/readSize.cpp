#include "readSize.h"
#include <stdexcept>

void readSize(std::ifstream& in, size_t& rows, size_t& cols)
{
  if (!in)
  {
    in >> rows >> cols;
  }
  else
  {
    throw std::runtime_error("Invalid input file");
  }
}
