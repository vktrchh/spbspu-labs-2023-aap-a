#include "regular.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
#include <stdexcept>

nikitov::Regular::Regular(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  double firstLine = pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2);
  double secondLine = pow(thirdPoint_.x - secondPoint_.x, 2) + pow(thirdPoint_.y - secondPoint_.y, 2);
  double thirdLine = pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2);
  if (!(firstLine + secondLine == thirdLine || secondLine + thirdLine == firstLine)
    || std::max(sqrt(firstLine), sqrt(thirdLine)) > sqrt(secondLine) * 2)
  {
    throw std::invalid_argument("Error: invalid regular agrugments");
  }
}

nikitov::Regular::~Regular()
{}

double nikitov::Regular::getArea() const
{
  double firstLine = sqrt(pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2));
  double thirdLine = sqrt(pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  int n = round(-2 * M_PI / (asin(inRadius / circumRadius) * 2 - M_PI));

  double a = 2 * circumRadius * sin(M_PI / n);
  return 0.5 * n * a * inRadius;
}

nikitov::rectangle_t nikitov::Regular::getFrameRect() const
{
  double firstLine = sqrt(pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2));
  double thirdLine = sqrt(pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  size_t n = round(-2 * M_PI / (asin(inRadius / circumRadius) * 2 - M_PI));
  double a = 2 * circumRadius * sin(M_PI / n);

  double maxX = std::numeric_limits < double >::min();
  double maxY = maxX;
  double minX = std::numeric_limits < double >::max();
  double minY = minX;

  point_t point;
  if (circumRadius == firstLine)
  {
    point = secondPoint_;
  }
  else
  {
    point = thirdPoint_;
  }

  point.x = point.x - firstPoint_.x;
  point.y = point.y - firstPoint_.y;
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
  return { maxX - minX, maxY - minY, firstPoint_ };
}

void nikitov::Regular::move(const point_t& point)
{
  double dx = point.x - firstPoint_.x;
  double dy = point.y - firstPoint_.y;
  move(dx, dy);
}

void nikitov::Regular::move(double dx, double dy)
{
  firstPoint_.x += dx;
  firstPoint_.y += dy;
  secondPoint_.x += dx;
  secondPoint_.y += dy;
  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}

void nikitov::Regular::scale(double ratio)
{
  secondPoint_.x = firstPoint_.x + (secondPoint_.x - firstPoint_.x) * ratio;
  secondPoint_.y = firstPoint_.y + (secondPoint_.y - firstPoint_.y) * ratio;
  thirdPoint_.x = firstPoint_.x + (thirdPoint_.x - firstPoint_.x) * ratio;
  thirdPoint_.y = firstPoint_.y + (thirdPoint_.y - firstPoint_.y) * ratio;
}
