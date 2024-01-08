#include "isoScale.hpp"

void rebdev::isoScale(Shape ** shapes, const int & numOfShape, const point_t & scalePoint, const double & k)
{
  for (int i = 0; i < numOfShape; ++i)
  {
    point_t center = shapes[i]->getFrameRect().pos_;
    shapes[i]->move(scalePoint);
    shapes[i]->scale(k);
    point_t newDistance = {(scalePoint.x_ - center.x_) * k, (scalePoint.y_ - center.y_) * k};
    shapes[i]->move(newDistance.x_, newDistance.y_);
  }
};
