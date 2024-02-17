#include "check_functions.hpp"

bool lopatina::isRectangleCorrect(point_t low_left, point_t up_right)
{
  if ((low_left.x_ == up_right.x_) || (low_left.y_ == up_right.y_))
  {
    return false;
  }
  if (((low_left.x_ > up_right.x_) && (low_left.y_ < up_right.y_)) || ((low_left.y_ > up_right.y_) && (low_left.x_ < up_right.x_)))
  {
    return false;
  }
  return true;
}

bool lopatina::isTriangleCorrect(point_t p1, point_t p2, point_t p3)
{
  if (((p1.x_ == p2.x_) && (p1.y_ == p2.y_)) || ((p2.x_ == p3.x_) && (p2.y_ == p3.y_)) || ((p3.x_ == p1.x_) && (p3.y_ == p1.y_)))
  {
    return false;
  }
  if (((p1.x_ == p2.x_) && (p2.x_  == p3.x_)) || ((p1.y_ == p2.y_) && (p2.y_ == p3.y_)))
  {
    return false;
  }
  return true;
}

bool lopatina::isCentralPoint(point_t point1, point_t point2, point_t point3)
{
  if (((point1.x_ == point2.x_) && (point1.y_ == point3.y_)) || ((point1.x_ == point3.x_) && (point1.y_ == point2.y_)))
  {
    return true;
  }
  return false;
}

lopatina::point_t lopatina::defineSidePointX(point_t point1, point_t point2, point_t point3)
{
  if (point1.x_ == point2.x_)
  {
    return point3;
  }
  else
  {
    return point2;
  }
}

lopatina::point_t lopatina::defineSidePointY(point_t point1, point_t point2, point_t point3)
{
    if (point1.y_ == point2.y_)
  {
    return point3;
  }
  else
  {
    return point2;
  }
}
