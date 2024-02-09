#include "checkTriangle.hpp"
#include <cmath>
#include <stdexcept>

void marishin::checkTriangle(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint)
{
  const point_t& p1 = firstPoint;
  const point_t& p2 = secondPoint;
  const point_t& p3 = thirdPoint;

  double ab = std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  double ac = std::sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
  double bc = std::sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));

  if (ab >= ac + bc || bc >= ab + ac || ac >= ab + bc)
  {
    throw std::invalid_argument("Irregular triangle");
  }
}

double marishin::getAreaTriangle(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint)
{
  const point_t& p1 = firstPoint;
  const point_t& p2 = secondPoint;
  const point_t& p3 = thirdPoint;

  double ab = std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  double ac = std::sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
  double bc = std::sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
  double abc = (ab + bc + ac) / 2;
  return std::sqrt(abc * (abc - ab) * (abc - bc) * (abc - ac));
}

marishin::rectangle_t marishin::getFrameRectTriangle(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint)
{
  const point_t& p1 = firstPoint;
  const point_t& p2 = secondPoint;
  const point_t& p3 = thirdPoint;

  double height = (std::max(p1.y, (std::max(p2.y, p3.y))) - (std::min(p1.y, (std::min(p2.y, p3.y)))));
  double width = (std::max(p1.x, (std::max(p2.x, p3.x))) - (std::min(p1.x, (std::min(p2.x, p3.x)))));
  point_t pos = { (std::min(p1.x, (std::min(p2.x, p3.x)))) + width / 2, (std::min(p1.y, (std::min(p2.y, p3.y)))) + height / 2 };
  return { pos, width, height };
}
