#include "parallelogram.hpp"
#include <stdexcept>

arakelyan::Parallelogram::Parallelogram(point_t fp, point_t sp, point_t tp):
  p1_(fp),
  p2_(sp),
  p3_(tp),
  p4_{(p1_.x + (p3_.x - p2_.x)),(p3_.y)},
  midpoint_{(p1_.x + ((p3_.x - p1_.x) / 2.0)),(p3_.y - ((p3_.y - p2_.y) / 2.0))}
{
  if (p2_.x - p1_.x != p3_.x - p4_.x)
  {
    throw std::logic_error("The provided points do not form a parallelogram!");
  }
};

double arakelyan::Parallelogram::getArea() const
{
  return std::abs((p2_.x - p1_.x) * (p1_.y - p3_.y));
}

rectangle_t arakelyan::Parallelogram::getFrameRect()
{
  double width = std::abs(p3_.x - p1_.x);
  double height = std::abs(p1_.y - p3_.y);
  point_t midPointOfRect = {(p1_.x + p3_.x) / 2.0,(p1_.y + p3_.y) / 2.0};
  rectangle_t data = {width, height, midPointOfRect};
  return data;
}

void arakelyan::Parallelogram::move(const point_t point)
{
  double dx = point.x - midpoint_.x;
  double dy = point.y - midpoint_.y;
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p4_.y += dy;
  midpoint_ = point;
}

void arakelyan::Parallelogram::move(const double delX, const double delY)
{
  p1_.x += delX;
  p1_.y += delY;
  p2_.x += delX;
  p2_.y += delY;
  p3_.x += delX;
  p3_.y += delY;
  p4_.x += delX;
  p4_.y += delY;
  midpoint_.x += delX;
  midpoint_.y += delY;
}

void arakelyan::Parallelogram::scale(const double k)
{
  if (k < 0.0)
  {
    throw std::logic_error("The coefficient cannot be less than zero! (Parallelogram)");
  }
  rectangle_t dataOfRect = getFrameRect();
  double widthWithScale = dataOfRect.width * k;
  double heightWithScale = dataOfRect.height * k;
  p1_.x = midpoint_.x - (widthWithScale / 2.0);
  p1_.y = midpoint_.y - (heightWithScale / 2.0);
  p2_.x = midpoint_.x + (widthWithScale / 4.0);
  p2_.y = midpoint_.y - (heightWithScale / 2.0);
  p3_.x = midpoint_.x + (widthWithScale / 2.0);
  p3_.y = midpoint_.y + (heightWithScale / 2.0);
  p4_.x = midpoint_.x - (widthWithScale / 4.0);
  p4_.y = midpoint_.y + (heightWithScale / 2.0);
}

arakelyan::Parallelogram::~Parallelogram()
{};
