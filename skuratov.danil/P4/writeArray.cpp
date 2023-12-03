#include "writeArray.h"

void writeArray(std::ostream& out, int input[], size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
  	if (!out)
  	{
  	  out << input[i];
  	}
  	else
  	{
  	  throw std::runtime_error("Error output file");
  	}
  }
}
