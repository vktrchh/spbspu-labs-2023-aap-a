#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>

agarkov::Parallelogram::Parallelogram(point_t point1, point_t point2, point_t point3):
  point1_(point1),
  point2_(point2),
  point3_(point3)
{
  if (!isCorrectParallelogram())
  {
    throw std::invalid_argument("Incorrect parallelogram argument");
  }
}

double agarkov::Parallelogram::getArea() const
{
  return std::fabs((point1_.x_ - point3_.x_) * (point2_.y_ - point1_.y_) - (point1_.x_ - point2_.x_) * (point3_.y_ - point1_.y_));
}

agarkov::rectangle_t agarkov::Parallelogram::getFrameRectangle() const
{
  point_t centre_frame_rect = getLineCenter(point2_, point3_);
  double height_frame_rect = std::fabs(point2_.y_ - point1_.y_);
  double width_frame_rect = std::fabs(point3_.y_ - point1_.y_);
  return {centre_frame_rect, width_frame_rect, height_frame_rect};
}

void agarkov::Parallelogram::move(double dx, double dy)
{
  point1_.move(dx, dy);
  point2_.move(dx, dy);
  point3_.move(dx, dy);
}

void agarkov::Parallelogram::move(agarkov::point_t position)
{
  point_t centre = getLineCenter(point1_, point3_);
  double dx = position.x_ - centre.x_;
  double dy = position.y_ - centre.y_;
  move(dx, dy);
}

void agarkov::Parallelogram::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  point_t center = getFrameRectangle().pos_;
  point1_.unsaveScale(center, k);
  point2_.unsaveScale(center, k);
  point3_.unsaveScale(center, k);
}

bool agarkov::Parallelogram::isCorrectParallelogram() const
{
  return (point1_.y_ == point2_.y_) && (point2_.y_ != point3_.y_);
}
