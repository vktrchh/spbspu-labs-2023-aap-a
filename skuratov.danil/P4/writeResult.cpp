#include "writeResult.h"
#include <stdexcept>

void writeResult(std::ostream& out, int input)
{
  if (out)
  {
    out << input;
  }
  else
  {
    throw std::runtime_error("Error output file");
  }
}
