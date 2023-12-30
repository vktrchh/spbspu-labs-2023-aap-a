#include "geometric_functions.hpp"
#include <cmath>

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



