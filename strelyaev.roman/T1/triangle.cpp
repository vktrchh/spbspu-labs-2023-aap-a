#include "triangle.hpp"
#include <cmath>
#include <algorithm>

strelyaev::Triangle::Triangle(point_t p1, point_t p2, point_t p3):
  p1_(p1),
  p2_(p2),
  p3_(p3),
  center_({(p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3})
{}

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

strelyaev::rectangle_t strelyaev::Triangle::getFrameRect()
{
  double up = std::max(p1_.y, std::max(p2_.y, p3_.y));
  double down = std::min(p1_.y, std::min(p2_.y, p3_.y));
  double left = std::min(p1_.x, std::min(p2_.x, p3_.x));
  double right = std::max(p1_.x, std::max(p2_.x, p3_.x));

  double center_x = (right + left) / 2.0;
  double center_y = (up + down) / 2.0;
  point_t r_center = {center_x, center_y};

  rectangle_t r1 = {right - left, up - down, r_center};
  return r1;
}

void strelyaev::Triangle::move(point_t new_center)
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

void strelyaev::Triangle::move(double k)
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

void strelyaev::Triangle::move(double dx, double dy)
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

void strelyaev::Triangle::scale(double k)
{
  p1_.x = center_.x + (p1_.x - center_.x) * k;
  p1_.y = center_.y + (p1_.y - center_.y) * k;

  p2_.x = center_.x + (p2_.x - center_.x) * k;
  p2_.y = center_.y + (p2_.y - center_.y) * k;

  p3_.x = center_.x + (p3_.x - center_.x) * k;
  p3_.y = center_.y + (p3_.y - center_.y) * k;
}

