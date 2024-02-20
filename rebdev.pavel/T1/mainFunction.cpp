#include "mainFunction.hpp"

void rebdev::deleteShapes(Shape ** shapes, size_t numOfShape)
{
  for (size_t i = 0; i < numOfShape; ++i)
  {
    delete shapes[i];
  }

  delete[] shapes;
}
