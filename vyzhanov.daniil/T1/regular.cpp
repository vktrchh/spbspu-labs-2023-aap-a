#include "regular.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>

vyzhanov::Regular::Regular(const point_t& p1, const point_t& p2, const point_t& p3) :
  a_(p1),
  b_(p2),
  c_(p3)
{
  double bigRad = std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2);
  double smallRad = std::pow((p1.x - p3.x), 2) + std::pow((p1.y - p3.y), 2);
  double foundation = std::pow((p2.x - p3.x), 2) + std::pow((p2.y - p3.y), 2);
  bool isReg = !(smallRad + foundation == bigRad);
  isReg = isReg && !(foundation + bigRad == smallRad);
  isReg = isReg || (std::max(std::sqrt(bigRad), std::sqrt(foundation)) > std::sqrt(smallRad) * 2);
  if (isReg)
  {
    throw std::invalid_argument("Error: invalid regular agrugments");
  }
}

double vyzhanov::Regular::getArea() const
{
  double bigRad = std::pow((a_.x - b_.x), 2) + std::pow((a_.y - b_.y), 2);
  double smallRad = std::pow((a_.x - c_.x), 2) + std::pow((a_.y - c_.y), 2);
  double replace = 0;
  double PI = 3.14159265358979323846;
  if (bigRad < smallRad)
  {
    replace = bigRad;
    bigRad = smallRad;
    smallRad = replace;
    replace = 0;
  }
  int sideCount = std::round(-2.0 * PI / (std::asin(smallRad / bigRad) * 2.0 - PI));
  double len = 2.0 * bigRad * std::sin(PI / sideCount);
  return 0.5 * sideCount * len * smallRad;
}

vyzhanov::rectangle_t vyzhanov::Regular::getFrameRect() const
{
  double bigRad = std::pow((a_.x - b_.x), 2) + std::pow((a_.y - b_.y), 2);
  double smallRad = std::pow((a_.x - c_.x), 2) + std::pow((a_.y - c_.y), 2);
  double replace = 0;
  double PI = 3.14159265358979323846;
  if (bigRad < smallRad)
  {
    replace = bigRad;
    bigRad = smallRad;
    smallRad = replace;
    replace = 0;
  }
  int sideCount = std::round(-2.0 * PI / (std::asin(smallRad / bigRad) * 2.0 - PI));
  double len = 2.0 * bigRad * std::sin(PI / sideCount);
  double maxX = std::numeric_limits< double >::lowest();
  double maxY = maxX;
  double minX = std::numeric_limits< double >::max();
  double minY = minX;

  point_t point;
  if (bigRad == std::pow((a_.x - b_.x), 2) + std::pow((a_.y - b_.y), 2))
  {
    point = b_;
  }
  else
  {
    point = c_;
  }

  point.x = point.x - a_.x;
  point.y = point.y - a_.y;
  double angle = 2.0 * asin(len / 2.0 / bigRad);
  for (size_t i = 0; i != sideCount; ++i)
  {
    double x = point.x;
    double y = point.y;
    point.x = x * std::cos(angle) - y * std::sin(angle);
    point.y = y * std::cos(angle) + x * std::sin(angle);
    maxX = std::max(maxX, point.x);
    minX = std::min(minX, point.x);
    maxY = std::max(maxY, point.y);
    minY = std::min(minY, point.y);
  }
  return { maxX - minX, maxY - minY, a_ };
}

void vyzhanov::Regular::move(const point_t& point)
{
    double dx = point.x - a_.x;
    double dy = point.y - a_.y;
    move(dx, dy);
}

void vyzhanov::Regular::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
}

void vyzhanov::Regular::scale(double ratio)
{
  b_.x = a_.x + (b_.x - a_.x) * ratio;
  b_.y = a_.y + (b_.y - a_.y) * ratio;
  c_.x = a_.x + (c_.x - a_.x) * ratio;
  c_.y = a_.y + (c_.y - a_.y) * ratio;
}
