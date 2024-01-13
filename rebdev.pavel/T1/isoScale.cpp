#include "isoScale.hpp"
#include <iostream>

void rebdev::isoScale(Shape ** shapes, const int & numOfShape, const point_t & scalePoint, const double & k)
{
  for (int i = 0; i < numOfShape; ++i)
  {
    shapes[i]->move(scalePoint);
    shapes[i]->scale(k);
  }
};
