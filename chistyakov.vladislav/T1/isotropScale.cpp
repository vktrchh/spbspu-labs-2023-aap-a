#include "isotropScale.hpp"

void chistyakov::isotropScale(Shape ** shapes, const point_t & point, const double ratio, const size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    point_t startPoint = shapes[i]->getFrameRect().pos;
    shapes[i]->move(point);
    shapes[i]->scale(ratio);
    point_t newPoint = { (startPoint.x - point.x) * ratio, (startPoint.y - point.y) * ratio };
    shapes[i]->move(newPoint);
  }
}
