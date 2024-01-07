#include "calculatetriangle.hpp"

double calculateDistance(const point_t& p1, const point_t& p2)
{
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool isTriangleExist(const point_t& p1, const point_t& p2, const point_t& p3)
{
  double a = calculateDistance(p1, p2);
  double b = calculateDistance(p2, p3);
  double c = calculateDistance(p3, p1);

  return (a + b > c) && (b + c > a) && (c + a > b);
}

