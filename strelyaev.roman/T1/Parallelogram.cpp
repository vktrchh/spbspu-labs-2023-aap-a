#include "Parallelogram.hpp"
#include <cmath>
#include <algorithm>
strelyaev::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  p4_({p2_.x + p3_.x - p1_.x, p2_.y + p3_.y - p1_.y}),
  center_({(p1_.x + p3_.x) / 2.0, (p1_.y + p3_.y) / 2.0})
{}

double strelyaev::Parallelogram::getArea() const
{
  return std::abs((p1_.x * (p2_.y - p3_.y) + p2_.x * (p3_.y - p1_.y) + p3_.x * (p1_.y - p2_.y)));
}
strelyaev::rectangle_t strelyaev::Parallelogram::getFrameRect()
{
  double up = std::max(p1_.y, std::max(p2_.y, p3_.y));
  double down = std::min(p1_.y, std::min(p2_.y, p3_.y));
  double left = std::min(p1_.x, std::min(p2_.x, p3_.x));
  double right = std::max(p1_.x, std::max(p2_.x, p3_.x));

  double center_x = (right + left) / 2.0;
  double center_y = (up + down) / 2.0;
  point_t r_center = {center_x, center_y};

  rectangle_t r1 = {up - down, right - left, r_center};
  return r1;
}
void strelyaev::Parallelogram::move(point_t new_center)
{
  double offset_x = new_center.x - center_.x;
  double offset_y = new_center.y - center_.y;
  p1_.x += offset_x;
  p1_.y += offset_y;
  p2_.x += offset_x;
  p2_.y += offset_y;
  p3_.x += offset_x;
  p3_.y += offset_y;
  center_ = new_center;
}
void strelyaev::Parallelogram::move(double k)
{
  center_.x += k;
  center_.y += k;
  p1_.x += k;
  p1_.y += k;
  p2_.x += k;
  p2_.y += k;
  p3_.x += k;
  p3_.y += k;
}

void strelyaev::Parallelogram::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}

void strelyaev::Parallelogram::scale(double k)
{
  p1_.x = center_.x + (p1_.x - center_.x) * k;
  p1_.y = center_.y + (p1_.y - center_.y) * k;

  p2_.x = center_.x + (p2_.x - center_.x) * k;
  p2_.y = center_.y + (p2_.y - center_.y) * k;

  p3_.x = center_.x + (p3_.x - center_.x) * k;
  p3_.y = center_.y + (p3_.y - center_.y) * k;
}


