#include "isoScale.hpp"

void rebdev::isoScale(Shape ** shapes, const int & numOfShape, const point_t & scalePoint, const double & k)
{
  for (int i = 0; i < numOfShape; ++i)
  {
    point_t centerPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scalePoint);
    shapes[i]->scale(k);
    shapes[i]->move((centerPoint.x - scalePoint.x) * k, (centerPoint.y - scalePoint.y) * k);
  }
};
