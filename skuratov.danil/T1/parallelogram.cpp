#include "parallelogram.h"

#include <stdexcept>

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
{}

skuratov::rectangle_t skuratov::Parallelogram::getFrameRect() const
{}

void skuratov::Parallelogram::move(const point_t& A)
{}

void skuratov::Parallelogram::move(double dx, double dy)
{}

void skuratov::Parallelogram::scale(double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Error: scale factor of parallelogram should be a positive");
  }
}
