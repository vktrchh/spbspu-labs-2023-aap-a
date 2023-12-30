#include "geometric_functions.hpp"
#include <cmath>
#include <stdexcept>

double namestnikov::getSizeOfLine(point_t p1, point_t p2)
{
  return std::sqrt((std::abs(p1.x - p2.x) * std::abs(p1.x - p2.x) + (std::abs(p1.y - p2.y) * std::abs(p1.y - p2.y));
}


double namestnikov::getAreaOfTriangle(const point_t p1, const point_t p2, const point_t p3)
{
  double a = getSizeOfline(p1, p2);
  double b = getSizeOfLine(p1, p3);
  double c = getSizeOfLine(p2, p3);
  double halfPerimetr = (a + b + c) / 2;
  return std::sqrt(halfPerimetr * (halfPerimetr - a) * (halfPerimetr - b) * (halfPerimetr - c));
}

point_t namestnikov::getIntersectionOfTwoLines(point_t * points)
{
  double a1 = 0, b1 = 0, c1 = 0;
  double a2 = 0, b2 = 0, c2 = 0;
  fillLineCoefficients(points[0], points[1], a1, b1, c1);
  fillLineCoefficients(points[2], points[3], a2, b2, c2);
  if ((a1 / a2) == (b1 / b2))
  {
    throw std::invalid_argument("There is no intersection\n");
  }
  else
  {
    double x = 0, y = 0;
    double d = a1 * b2 - b1 * a2;
    double dx = c1 * b2 - c2 * b1;
    double dy = a1 * c2 - c1 * a2;
    x = dx / d;
    y = dy / d;
    return {x, y};
  }
}



