#include "regular.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>

nikitov::Regular::Regular(const point_t& first, const point_t& second, const point_t& third):
  first_(first),
  second_(second),
  third_(third)
{
  double firstLine = pow(first_.x - second_.x, 2) + pow(first_.y - second_.y, 2);
  double secondLine = pow(third_.x - second_.x, 2) + pow(third_.y - second_.y, 2);
  double thirdLine = pow(first_.x - third_.x, 2) + pow(first_.y - third_.y, 2);
  if (!(firstLine + secondLine == thirdLine || secondLine + thirdLine == firstLine)
    || std::max(sqrt(firstLine), sqrt(thirdLine)) > sqrt(secondLine) * 2)
  {
    throw std::invalid_argument("Error: invalid regular agrugments");
  }
}

double nikitov::Regular::getArea() const
{
  const double PI = 3.141592653589793;
  double firstLine = sqrt(pow(first_.x - second_.x, 2) + pow(first_.y - second_.y, 2));
  double thirdLine = sqrt(pow(first_.x - third_.x, 2) + pow(first_.y - third_.y, 2));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  int n = round(-2 * PI / (asin(inRadius / circumRadius) * 2 - PI));

  double a = 2 * circumRadius * sin(PI / n);
  return 0.5 * n * a * inRadius;
}

nikitov::rectangle_t nikitov::Regular::getFrameRect() const
{
  const double PI = 3.141592653589793;
  double firstLine = sqrt(pow(first_.x - second_.x, 2) + pow(first_.y - second_.y, 2));
  double thirdLine = sqrt(pow(first_.x - third_.x, 2) + pow(first_.y - third_.y, 2));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  size_t n = round(-2 * PI / (asin(inRadius / circumRadius) * 2 - PI));
  double a = 2 * circumRadius * sin(PI / n);

  double maxX = std::numeric_limits < double >::min();
  double maxY = maxX;
  double minX = std::numeric_limits < double >::max();
  double minY = minX;

  point_t point;
  if (circumRadius == firstLine)
  {
    point = second_;
  }
  else
  {
    point = third_;
  }

  point.x = point.x - first_.x;
  point.y = point.y - first_.y;
  double angle = 2 * asin(a / 2  / circumRadius);
  for (size_t i = 0; i != n; ++i)
  {
    double x = point.x;
    double y = point.y;
    point.x = x * cos(angle) - y * sin(angle);
    point.y = y * cos(angle) + x * sin(angle);
    maxX = std::max(maxX, point.x);
    minX = std::min(minX, point.x);
    maxY = std::max(maxY, point.y);
    minY = std::min(minY, point.y);
  }
  return { maxX - minX, maxY - minY, first_ };
}

void nikitov::Regular::move(const point_t& point)
{
  double dx = point.x - first_.x;
  double dy = point.y - first_.y;
  move(dx, dy);
}

void nikitov::Regular::move(double dx, double dy)
{
  first_.x += dx;
  first_.y += dy;
  second_.x += dx;
  second_.y += dy;
  third_.x += dx;
  third_.y += dy;
}

void nikitov::Regular::scale(double ratio)
{
  second_.x = first_.x + (second_.x - first_.x) * ratio;
  second_.y = first_.y + (second_.y - first_.y) * ratio;
  third_.x = first_.x + (third_.x - first_.x) * ratio;
  third_.y = first_.y + (third_.y - first_.y) * ratio;
}
