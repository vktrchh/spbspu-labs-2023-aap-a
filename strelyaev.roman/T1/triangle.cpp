#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>



#include <iostream>
strelyaev::Triangle::Triangle(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{
  double determinant = p1_.x * (p2_.y - p3_.y) - p2_.x * (p1_.y - p3_.y) + p3_.x * (p1_.y - p2_.y);
  if (determinant == 0)
  {
    throw std::invalid_argument("Invalid points for TRIANGLE");
  }
}

double strelyaev::Triangle::getDistance(const point_t p1, const point_t p2) const
{
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}


double strelyaev::Triangle::getArea() const
{
  double a = Triangle::getDistance(p1_, p2_);
  double b = Triangle::getDistance(p2_, p3_);
  double c = Triangle::getDistance(p3_, p1_);
  double half_per = (a + b + c) / 2.0;
  return std::sqrt(half_per * (half_per - a) * (half_per - b) * (half_per - c));
}

strelyaev::rectangle_t strelyaev::Triangle::getFrameRect() const
{
  double up = std::max({p1_.y, p2_.y, p3_.y});
  double down = std::min({p1_.y, p2_.y, p3_.y});
  double left = std::min({p1_.x, p2_.x, p3_.x});
  double right = std::max({p1_.x, p2_.x, p3_.x});

  double r_center_x = (right + left) / 2.0;
  double r_center_y = (up + down) / 2.0;
  point_t r_center = {r_center_x, r_center_y};

  rectangle_t r1 = {right - left, up - down, r_center};
  return r1;
}

void strelyaev::Triangle::move(point_t new_center)
{
  double offset_x = new_center.x;
  double offset_y = new_center.y;
  p1_.x += offset_x;
  p2_.x += offset_x;
  p3_.x += offset_x;
  p1_.y += offset_y;
  p2_.y += offset_y;
  p3_.y += offset_y;
}

void strelyaev::Triangle::move(double k)
{
  p1_.x += k;
  p1_.y += k;
  p2_.x += k;
  p2_.y += k;
  p3_.x += k;
  p3_.y += k;
}

void strelyaev::Triangle::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}

void strelyaev::Triangle::scale(double k)
{
  point_t center = {(p1_.x + p2_.x + p3_.x) / 3, (p1_.y + p2_.y + p3_.y) / 3};
  p1_.x = center_.x + (p1_.x - center_.x) * k;
  p1_.y = center_.y + (p1_.y - center_.y) * k;

  p2_.x = center_.x + (p2_.x - center_.x) * k;
  p2_.y = center_.y + (p2_.y - center_.y) * k;

  p3_.x = center_.x + (p3_.x - center_.x) * k;
  p3_.y = center_.y + (p3_.y - center_.y) * k;
}

