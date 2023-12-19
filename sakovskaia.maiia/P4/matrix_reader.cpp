#include "matrix.hpp"
#include "matrix_input_res.hpp"

void sakovskaia::inputMatrix(std::ifstream & input, int * a, int b)
{
  for (int i = 0; i < b; i++)
  {
    if (!(input >> a[i]))
    {
      throw (std::logic_error("Cannot create matrix"));
    }
  }
}

std::ofstream & sakovskaia::printAnswer(std::ofstream & output, int * a, int b)
{
  for (int i = 0; i < b; i++)
  {
    output << a[i];
  }
}
