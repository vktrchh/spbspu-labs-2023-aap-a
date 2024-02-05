#include "isoScale.hpp"
#include <iostream>

void rebdev::isoScale(Shape ** shapes, const int & numOfShape, const point_t & scalePoint, const double & k)
{
  for (int i = 0; i < numOfShape; ++i)
  {
    point_t centerPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scalePoint);
    shapes[i]->scale(k);
    shapes[i]->move((scalePoint.x - centerPoint.x) * k, (scalePoint.y - centerPoint.y) * k);
  }
};
