#include "matrix.hpp"

void sakovskaia::staticMatrix(std::ifstream & input, int * a, int b)
{
  for (int i = 0; i < b; i++)
  {
    if (!(input >> a[i]))
    {
      throw (std::logic_error("Cannot create matrix"));
    }
  }
}

void sakovskaia::dynamicMatrix(std::ifstream & input, int * a, int b)
{
  for (int i = 0; i < b; i++)
  {
    if (!(input >> a[i]))
    {
      delete [] a;
      throw (std::logic_error("Cannot create matrix"));
    }
  }
}

void sakovskaia::printAnswer(std::ofstream & output, int * a, int b)
{
  for (int i = 0; i < b; i++)
  {
    output << a[i];
  }
}
