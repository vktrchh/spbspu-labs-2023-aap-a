#include "readSize.h"
#include <stdexcept>

void readSize(std::ifstream& in, size_t& rows, size_t& cols)
{
  in >> rows >> cols;
  if (!in)
  {
    throw std::runtime_error("Invalid input file");
  }
}
