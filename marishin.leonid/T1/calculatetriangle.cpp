#include "calculatetriangle.hpp"
#include <iostream>
#include <cmath>

double marishin::calculateDistance(const point_t& p1, const point_t& p2)
{
  return (std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

bool marishin::isTriangleExist(const point_t& p1, const point_t& p2, const point_t& p3)
{
  double a = calculateDistance(p1, p2);
  double b = calculateDistance(p2, p3);
  double c = calculateDistance(p3, p1);

  return ((a + b <= c) || (b + c <= a) || (c + a <= b));
}

double marishin::calculateTriangleArea(const point_t& p1, const point_t& p2, const point_t& p3)
{
  double a = calculateDistance(p1, p2);
  double b = calculateDistance(p2, p3);
  double c = calculateDistance(p3, p1);
  double abc = (a + b + c) / 2;
  return (std::sqrt(abc * (abc - a) * (abc - b) * (abc - c)));
}
