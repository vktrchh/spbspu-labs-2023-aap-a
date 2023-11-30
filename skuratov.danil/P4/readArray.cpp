#include "readArray.h"

void readArray(std::ifstream in, int array[], const size_t& size)
{
  if (!in)
  {
  	for (size_t i = 0; i < size - 1; ++i)
  	{
      if (std::isdigit(array[i]))
      {
        in >> array[i];
      }
      else
      {
        throw std::runtime_error("Invalid array");
      }
  	}
  }
  else
  {
    throw std::runtime_error("Invalid input file");
  }
}