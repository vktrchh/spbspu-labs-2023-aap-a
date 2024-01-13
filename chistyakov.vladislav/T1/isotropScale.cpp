#include "isotropScale.hpp"

void chistyakov::isotropScale(Shape * shape, const point_t & point, const double ratio)
{
  point_t startPoint = shape->getFrameRect().pos;
  shape->move(point);
  shape->scale(ratio);
  point_t newPoint = { (startPoint.x - point.x) * ratio, (startPoint.y - point.y) * ratio };
  shape->move(newPoint);
}
