#include "regular.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>

vyzhanov::Regular::Regular(const point_t& p1, const point_t& p2, const point_t& p3):
  mainTri_(Triangle(p1, p2, p3)),
  a_(p1),
  b_(p2),
  c_(p3)
{
  double firstLine = std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2);
  double secondLine = std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2);
  double foundation = std::pow(p2.x - p3.x, 2) + std::pow(p2.y - p3.y, 2);
  bool isReg = !(firstLine + foundation == secondLine);
  isReg = isReg && !(foundation + secondLine == firstLine);
  isReg = isReg || (std::max(std::sqrt(firstLine), std::sqrt(secondLine)) > std::sqrt(foundation) * 2);
  if (isReg)
  {
    throw std::invalid_argument("Error: invalid regular agrugments");
  }
}

double vyzhanov::Regular::getArea() const
{
  double firstLine = std::sqrt(std::pow(a_.x - b_.x, 2) + std::pow(a_.y - b_.y, 2));
  double secondLine = std::sqrt(std::pow(a_.x - c_.x, 2) + std::pow(a_.y - c_.y, 2));
  const double PI = 3.14159265358979323846;
  double smallRad = std::min(firstLine, secondLine);
  double bigRad = std::max(firstLine, secondLine);
  int sideCount = std::round(-2.0 * PI / (std::asin(smallRad / bigRad) * 2.0 - PI));
  return mainTri_.getArea() * sideCount * 2;
}

vyzhanov::rectangle_t vyzhanov::Regular::getFrameRect() const
{
  double firstLine = std::sqrt(std::pow(a_.x - b_.x, 2) + std::pow(a_.y - b_.y, 2));
  double secondLine = std::sqrt(std::pow(a_.x - c_.x, 2) + std::pow(a_.y - c_.y, 2));
  double PI = 3.14159265358979323846;
  double smallRad = std::min(firstLine, secondLine);
  double bigRad = std::max(firstLine, secondLine);
  size_t sideCount = std::round(-2.0 * PI / (std::asin(smallRad / bigRad) * 2.0 - PI));
  double len = 2.0 * bigRad * std::sin(PI / sideCount);
  double maxX = std::numeric_limits< double >::lowest();
  double maxY = maxX;
  double minX = std::numeric_limits< double >::max();
  double minY = minX;

  point_t point;
  if (bigRad == firstLine)
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
  return { maxX - minX, maxY - minY, a_};
}

void vyzhanov::Regular::move(const point_t& point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void vyzhanov::Regular::move(double dx, double dy)
{
  mainTri_.move(dx, dy);
}

void vyzhanov::Regular::scale(double ratio)
{
  point_t center1 = mainTri_.getFrameRect().pos;
  mainTri_.scale(ratio);
  mainTri_.move(center1);
}
