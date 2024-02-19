#include "check_functions.hpp"
#include <cmath>

bool lopatina::isRectangleCorrect(point_t low_left, point_t up_right)
{
  if ((low_left.x >= up_right.x) || (low_left.y >= up_right.y))
  {
    return false;
  }
  return true;
}

bool lopatina::isTriangleCorrect(point_t p1, point_t p2, point_t p3)
{
  double a = std::sqrt(std::pow(p1.x - p2.x, 2.0) + std::pow(p1.y - p2.y, 2.0));
  double b = std::sqrt(std::pow(p2.x - p3.x, 2.0) + std::pow(p2.y - p3.y, 2.0));
  double c = std::sqrt(std::pow(p1.x - p3.x, 2.0) + std::pow(p1.y - p3.y, 2.0));
  if ((a >= (b + c)) || (b >= (a + c)) || (c >= (a + b)))
  {
    return false;
  }
  return true;
}


bool lopatina::isCentralPoint(point_t point1, point_t point2, point_t point3)
{
  if (((point1.x == point2.x) && (point1.y == point3.y)) || ((point1.x == point3.x) && (point1.y == point2.y)))
  {
    return true;
  }
  return false;
}

lopatina::point_t lopatina::defineSidePointX(point_t point1, point_t point2, point_t point3)
{
  if (point1.x == point2.x)
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
    if (point1.y == point2.y)
  {
    return point3;
  }
  else
  {
    return point2;
  }
}
