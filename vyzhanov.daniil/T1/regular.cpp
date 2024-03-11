#include "regular.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>

vyzhanov::Regular::Regular(const point_t& p1, const point_t& p2, const point_t& p3):
  mainTri_(Triangle(p1, p2, p3)),
  points_{p1, p2, p3}
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
  double bigRad = std::pow((points_[0].x - points_[1].x), 2) + std::pow((points_[0].y - points_[1].y), 2);
  double smallRad = std::pow((points_[0].x - points_[2].x), 2) + std::pow((points_[0].y - points_[2].y), 2);
  double PI = 3.14159265358979323846;
  int sideCount = std::round(-2.0 * PI / (std::asin(std::max(smallRad, bigRad)/ std::min(smallRad, bigRad)) * 2.0 - PI));
  return mainTri_.getArea() * sideCount * 2;
}

vyzhanov::rectangle_t vyzhanov::Regular::getFrameRect() const
{
  double bigRad = std::pow((points_[0].x - points_[1].x), 2) + std::pow((points_[0].y - points_[1].y), 2);
  double smallRad = std::pow((points_[0].x - points_[2].x), 2) + std::pow((points_[0].y - points_[2].y), 2);
  double PI = 3.14159265358979323846;
  int sideCount = std::round(-2.0 * PI / (std::asin(std::max(smallRad, bigRad) / std::min(smallRad, bigRad)) * 2.0 - PI));
  double len = 2.0 * bigRad * std::sin(PI / sideCount);
  double maxX = std::numeric_limits< double >::lowest();
  double maxY = maxX;
  double minX = std::numeric_limits< double >::max();
  double minY = minX;

  point_t point;
  if (bigRad == std::max(bigRad, smallRad))
  {
      point = points_[1];
  }
  else
  {
    point = points_[2];
  }

  point.x = point.x - points_[0].x;
  point.y = point.y - points_[0].y;
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
  return { maxX - minX, maxY - minY, points_[0]};
}

void vyzhanov::Regular::move(const point_t& point)
{
  double dx = point.x - points_[1].x;
  double dy = point.y - points_[1].y;
  move(dx, dy);
}

void vyzhanov::Regular::move(double dx, double dy)
{
    mainTri_.move(dx, dy);
}

void vyzhanov::Regular::scale(double ratio)
{
  mainTri_.scale(ratio);
  mainTri_.move(points_[1]);
}
