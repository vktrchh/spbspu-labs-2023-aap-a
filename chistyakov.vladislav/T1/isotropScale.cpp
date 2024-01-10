#include "isotropScale.hpp"

void chistyakov::isotropScale(Shape * shape, const point_t & point, const double ratio)
{
  point_t startPoint = shape->getFrameRect().pos;
  shape->move(point);
  shape->scale(ratio);
  point_t newPoint = { (point.x - startPoint.x) * ratio, (point.y - startPoint.y) * ratio };
  shape->move(newPoint);
}
