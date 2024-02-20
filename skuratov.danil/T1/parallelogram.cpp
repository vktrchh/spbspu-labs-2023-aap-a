#include "parallelogram.hpp"

#include <stdexcept>
#include <cmath>
#include <algorithm>

skuratov::point_t findCenOfParal(const skuratov::point_t& point1, const skuratov::point_t& point2, const skuratov::point_t& point3)
{
  skuratov::point_t mid1 = { (point1.x + point2.x) / 2, (point1.y + point2.y) / 2 };
  skuratov::point_t mid2 = { (point2.x + point3.x) / 2, (point2.y + point3.y) / 2 };

  double slope1 = (point1.y - point3.y) / (point1.x - point3.x);
  double slope2 = (point2.y - point3.y) / (point2.x - point3.x);

  skuratov::point_t center = {};
  center.x = (slope1 * mid1.x - slope2 * mid2.x + mid2.y - mid1.y) / (slope1 - slope2);
  center.y = slope1 * (center.x - mid1.x) + mid1.y;
  return center;
}

skuratov::Parallelogram::Parallelogram(const point_t& point1, const point_t& point2, const point_t& point3):
  point1_(point1),
  point2_(point2),
  point3_(point3)
{
  if ((point1_.x != point2_.x || point1_.y != point2_.y)
    || (point1_.x != point3_.x || point1_.y != point3_.y)
    || (point2_.x != point3_.x || point2_.y != point3_.y))
  {
    throw std::invalid_argument("All sides of the parallelogram must be parallel to the coordinate axes!");
  }
}

double skuratov::Parallelogram::getArea() const
{
  double side1 = std::sqrt(std::pow(point2_.x - point1_.x, 2) + std::pow(point2_.y - point1_.y, 2));
  double side2 = std::sqrt(std::pow(point3_.x - point1_.x, 2) + std::pow(point3_.y - point1_.y, 2));
  return side1 * side2;
}

skuratov::rectangle_t skuratov::Parallelogram::getFrameRect() const
{
  double width = std::abs(point2_.x - point3_.x) + std::abs(point1_.x - point2_.x);
  double height = (point1_.y == point2_.y) * std::abs(point2_.y - point3_.y) + (point1_.y != point2_.y) * std::abs(point1_.y - point2_.y);
  point_t center = findCenOfParal(point1_, point2_, point3_);
  return { width, height, center };
}

void skuratov::Parallelogram::move(const point_t& A)
{
  point_t center = findCenOfParal(point1_, point2_, point3_);
  double dx = A.x - center.x;
  double dy = A.y - center.y;
  move(dx, dy);
}

void skuratov::Parallelogram::move(double dx, double dy)
{
  point1_.x += dx;
  point2_.x += dx;
  point3_.x += dx;

  point1_.y += dy;
  point2_.y += dy;
  point3_.y += dy;
}

void skuratov::Parallelogram::scale(double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Error: scale factor of parallelogram should be a positive");
  }

  point_t center = findCenOfParal(point1_, point2_, point3_);

  point1_.x = center.x + scalingFactor * (point1_.x - center.x);
  point1_.y = center.y + scalingFactor * (point1_.y - center.y);

  point2_.x = center.x + scalingFactor * (point2_.x - center.x);
  point2_.y = center.y + scalingFactor * (point2_.y - center.y);

  point3_.x = center.x + scalingFactor * (point3_.x - center.x);
  point3_.y = center.y + scalingFactor * (point3_.y - center.y);
}
