#include "matrix.hpp"

void sakovskaia::staticMatrix(std::fstream & in, int * a, int b)
{
  for (int i = 0; i < b; i++)
  {
    if (!(in >> a[i]))
    {
      throw (std::logic_error("Cannot create matrix"));
    }
  }
}

void sakovskaia::dynamicMatrix(std::fstream & in, int * a, int b)
{
  for (int i = 0; i < b; i++)
  {
    if (!(in >> a[i]))
    {
      delete [] a;
      throw (std::logic_error("Cannot create matrix"));
    }
  }
}
