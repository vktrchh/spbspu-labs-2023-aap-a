#include "matrix.hpp"
#include "matrix_input_res.hpp"

void sakovskaia::inputMatrix(std::ifstream & input, int * a, size_t b)
{
  for (size_t i = 0; i < b; i++)
  {
    if (!(input >> a[i]))
    {
      throw (std::logic_error("Cannot create matrix"));
    }
  }
}

std::ofstream & sakovskaia::printAnswer(std::ofstream & output, int * a, int b)
{
  if (b > 0)
  {
    output << a[0];
    for (int i = 0; i < b; i++)
    {
      output << " " << a[i];
    }
  }
  return output;
}
