#include "Parallelogram.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

strelyaev::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_({p2_.x + p3_.x - p1_.x, p2_.y + p3_.y - p1_.y})
{
  double determinant = p1_.x * (p2_.y - p3_.y) - p2_.x * (p1_.y - p3_.y) + p3_.x * (p1_.y - p2_.y);
  if (determinant == 0)
  {
    throw std::invalid_argument("Invalid points for PARALLELOGRAM: Not a triangle");
  }
  if (!((p1_.y == p2_.y) || (p1_.y == p3_.y) || (p2_.y == p3_.y)))
  {
    throw std::invalid_argument("Invalid points for PARALLELOGRAM: Sides are not parallel to axis");
  }
}

double strelyaev::Parallelogram::getArea() const
{
  return std::abs((p1_.x * (p2_.y - p3_.y) + p2_.x * (p3_.y - p1_.y) + p3_.x * (p1_.y - p2_.y)));
}

strelyaev::rectangle_t strelyaev::Parallelogram::getFrameRect() const
{
  double min_x = std::min({p1_.x, p2_.x, p3_.x, p4_.x});
  double max_x = std::max({p1_.x, p2_.x, p3_.x, p4_.x});
  double min_y = std::min({p1_.y, p2_.y, p3_.y, p4_.y});
  double max_y = std::max({p1_.y, p2_.y, p3_.y, p4_.y});

  double width = max_x - min_x;
  double height = max_y - min_y;

  rectangle_t r1 = {width, height, {(max_x + min_x) / 2, (max_y + min_y) / 2}};
  return r1;
}
void strelyaev::Parallelogram::move(point_t new_center)
{
  point_t center = {(p1_.x + p2_.x + p3_.x) / 3, (p1_.y + p2_.y + p3_.y) / 3};
  double offset_x = new_center.x - center.x;
  double offset_y = new_center.y - center.y;

  p1_.x += offset_x;
  p1_.y += offset_y;
  p2_.x += offset_x;
  p2_.y += offset_y;
  p3_.x += offset_x;
  p3_.y += offset_y;
  p4_.x += offset_x;
  p4_.y += offset_y;
}

void strelyaev::Parallelogram::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
  p4_.x += dx;
  p4_.y += dy;
}

void strelyaev::Parallelogram::scale(double k)
{
  point_t center = {(p1_.x + p2_.x + p3_.x) / 3, (p1_.y + p2_.y + p3_.y) / 3};
  p1_.x = center.x + (p1_.x - center.x) * k;
  p1_.y = center.y + (p1_.y - center.y) * k;

  p2_.x = center.x + (p2_.x - center.x) * k;
  p2_.y = center.y + (p2_.y - center.y) * k;

  p3_.x = center.x + (p3_.x - center.x) * k;
  p3_.y = center.y + (p3_.y - center.y) * k;

  p4_.x = center.x + (p4_.x - center.x) * k;
  p4_.y = center.y + (p4_.y - center.y) * k;
}


