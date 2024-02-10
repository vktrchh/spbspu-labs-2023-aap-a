#include "isoScale.hpp"

void zakozhurnikova::isoScale(Shape* shape, const point_t& scalePoint, double k)
{
  point_t startPoint = shape->getFrameRect().pos;
  shape->move(scalePoint);
  point_t isoCenterPos = shape->getFrameRect().pos;
  shape->scale(k);
  shape->move(k * (startPoint.x - isoCenterPos.x), k * (startPoint.y - isoCenterPos.y));
}
