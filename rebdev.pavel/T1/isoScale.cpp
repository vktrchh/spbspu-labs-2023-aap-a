#include "isoScale.hpp"

void rebdev::isoScale(Shape ** shapes, const int & numOfShape, const point_t & scalePoint, const double & k)
{
  for (int i = 0; i < numOfShape; ++i)
  {
    point_t centerPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(scalePoint);
    point_t centerPoint2 = shapes[i]->getFrameRect().pos;
    shapes[i]->scale(k);
    shapes[i]->move((centerPoint.x - centerPoint2.x) * k, (centerPoint.y - centerPoint2.y) * k);
  }
}
