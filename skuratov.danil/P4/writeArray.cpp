#include "writeArray.h"
#include <stdexcept>

void writeArray(std::ostream& out, int input, size_t size)
{
  if (!out)
  {
    out << input;
  }
  else
  {
    throw std::runtime_error("Error output file");
  }
}
