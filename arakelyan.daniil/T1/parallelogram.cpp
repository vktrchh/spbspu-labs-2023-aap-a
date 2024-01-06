#include "parallelogram.hpp"
#include <stdexcept>

arakelyanParallelogram::Parallelogram::Parallelogram(point_t fp, point_t sp, point_t tp):
  p1_(fp),
  p2_(sp),
  p3_(tp),
  p4_{(p1_.x_ + (p3_.x_ - p2_.x_)),(p3_.y_)},
  midpoint_{(p1_.x_ + ((p3_.x_ - p1_.x_) / 2.0)),(p3_.y_ - ((p3_.y_ - p2_.y_) / 2.0))}
{
  if (p2_.x_ - p1_.x_ != p3_.x_ - p4_.x_)
  {
    throw std::logic_error("The provided points do not form a parallelogram!");
  }
};

double arakelyanParallelogram::Parallelogram::getArea() const
{
  return std::abs((p2_.x_ - p1_.x_) * (p1_.y_ - p3_.y_));
}

rectangle_t arakelyanParallelogram::Parallelogram::getFrameRect()
{
  double width = std::abs(p3_.x_ - p1_.x_);
  double height = std::abs(p1_.y_ - p3_.y_);
  point_t midPointOfRect = {(p1_.x_ + p3_.x_) / 2.0,(p1_.y_ + p3_.y_) / 2.0};
  rectangle_t data = {width, height, midPointOfRect};
  return data;
}

void arakelyanParallelogram::Parallelogram::move(const point_t point)
{
  double dx = point.x_ - midpoint_.x_;
  double dy = point.y_ - midpoint_.y_;
  p1_.x_ += dx;
  p1_.y_ += dy;
  p2_.x_ += dx;
  p2_.y_ += dy;
  p3_.x_ += dx;
  p4_.y_ += dy;
  midpoint_ = point;
}

void arakelyanParallelogram::Parallelogram::move(const double delX, const double delY)
{
  p1_.x_ += delX;
  p1_.y_ += delY;
  p2_.x_ += delX;
  p2_.y_ += delY;
  p3_.x_ += delX;
  p3_.y_ += delY;
  p4_.x_ += delX;
  p4_.y_ += delY;
  midpoint_.x_ += delX;
  midpoint_.y_ += delY;
}

void arakelyanParallelogram::Parallelogram::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("The coefficient cannot be less than zero! (Parallelogram)");
  }
  rectangle_t dataOfRect = getFrameRect();
  double widthWithScale = dataOfRect.width_ * k;
  double heightWithScale = dataOfRect.height_ * k;
  p1_.x_ = midpoint_.x_ - (widthWithScale / 2.0);
  p1_.y_ = midpoint_.y_ - (heightWithScale / 2.0);
  p2_.x_ = midpoint_.x_ + (widthWithScale / 4.0);
  p2_.y_ = midpoint_.y_ - (heightWithScale / 2.0);
  p3_.x_ = midpoint_.x_ + (widthWithScale / 2.0);
  p3_.y_ = midpoint_.y_ + (heightWithScale / 2.0);
  p4_.x_ = midpoint_.x_ - (widthWithScale / 4.0);
  p4_.y_ = midpoint_.y_ + (heightWithScale / 2.0);
}

arakelyanParallelogram::Parallelogram::~Parallelogram()
{};
