#include "geometryFunc.hpp"
#include <limits>
zakozhurnikova::point_t zakozhurnikova::getComplexquadCenter(const point_t* points)
{
  double x1 = points[0].x;
  double y1 = points[0].y;
  double x2 = points[1].x;
  double y2 = points[1].y;
  double x3 = points[2].x;
  double y3 = points[2].y;
  double x4 = points[3].x;
  double y4 = points[3].y;
  double determinant = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);
  double determinantX = (x2 - x1) * (y3 * (x4 - x3) - x3 * (y4 - y3)) - (x4 - x3) * (y1 * (x2 - x1) - x1 * (y2 - y1));
  double determinantY = (y2 - y1) * (y3 * (x4 - x3) - x3 * (y4 - y3)) - (y4 - y3) * (y1 * (x2 - x1) - x1 * (y2 - y1));
  return zakozhurnikova::point_t(determinantX / determinant, determinantY / determinant);
}

bool zakozhurnikova::hasIntersection(const point_t* points)
{
  double x1 = points[0].x;
  double y1 = points[0].y;
  double x2 = points[1].x;
  double y2 = points[1].y;
  double x3 = points[2].x;
  double y3 = points[2].y;
  double x4 = points[3].x;
  double y4 = points[3].y;
  double determinant = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);
  if (determinant - 0.0 <= std::numeric_limits<double>::epsilon())
  {
    return false;
  }
  return true;
}
