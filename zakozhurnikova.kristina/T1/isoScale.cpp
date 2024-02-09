#include "isoScale.hpp"

void zakozhurnikova::isoScale(Shape* shape, const point_t& scalePoint, double k)
{
  point_t originPoint = shape->getFrameRect().pos;
  shape->move(scalePoint);
  shape->scale(k);
  originPoint = originPoint.scaleShift(k, scalePoint);
  shape->move(originPoint);
}
