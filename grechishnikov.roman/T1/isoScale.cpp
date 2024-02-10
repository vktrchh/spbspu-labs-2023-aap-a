#include "isoScale.hpp"

void grechishnikov::isoScale(grechishnikov::Shape* shape, grechishnikov::point_t scalePoint, double ratio)
{
  grechishnikov::point_t initPoint = shape->getFrameRect().pos;
  shape->move(scalePoint);
  shape->scale(ratio);
  shape->move((initPoint.x - scalePoint.x) * ratio, (initPoint.y - scalePoint.y) * ratio);
}
