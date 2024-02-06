#include "isoscale.hpp"

void zakozhurnikova::isoScale(Shape* shape, const point_t& scalePoint, double k) 
{
  point_t originPoint = shape->getFrameRect().getCenter();
  shape->move(scalePoint);
  shape->scale(k);
  originPoint.scaleShift(k, scalePoint);
  shape->move(originPoint);
}
