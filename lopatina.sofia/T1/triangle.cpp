#include "triangle.hpp"
#include <cmath>
#include <algorithm>

lopatina::Triangle::Triangle(point_t point1, point_t point2, point_t point3)
{
  p1_.x = point1.x;
  p1_.y = point1.y;
  p2_.x = point2.x;
  p2_.y = point2.y;
  p3_.x = point3.x;
  p3_.y = point3.y;
  pos_tri_.x = (point1.x + point2.x + point3.x) / 3.0;
  pos_tri_.y = (point1.y + point2.y + point3.y) / 3.0;
}

double lopatina::Triangle::getArea() const
{
  return 0.5 * (std::abs ((p2_.x - p1_.x) * (p3_.y - p1_.y) - (p3_.x - p1_.x) * (p2_.y - p1_.y)));
}

lopatina::rectangle_t lopatina::Triangle::getFrameRect() const
{
  double max_x = std::max({p1_.x, p2_.x, p3_.x});
  double min_x = std::min({p1_.x, p2_.x, p3_.x});
  double max_y = std::max({p1_.y, p2_.y, p3_.y});
  double min_y = std::min({p1_.y, p2_.y, p3_.y});
  double height_tri_ = max_y - min_y;
  double width_tri_ = max_x - min_x;
  point_t pos_ = {min_x + (width_tri_ / 2.0), min_y + (height_tri_ / 2.0)};
  rectangle_t newRect{height_tri_, width_tri_, pos_};
  return newRect;
}

void lopatina::Triangle::move(point_t new_pos)
{
  double dx = new_pos.x - pos_tri_.x;
  double dy = new_pos.y - pos_tri_.y;
  move(dx, dy);
}

void lopatina::Triangle::move(double dx, double dy)
{
  pos_tri_.x += dx;
  pos_tri_.y += dy;
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}

void lopatina::Triangle::scale(double k)
{
  p1_.x = pos_tri_.x + (p1_.x - pos_tri_.x) * k;
  p1_.y = pos_tri_.y + (p1_.y - pos_tri_.y) * k;
  p2_.x = pos_tri_.x + (p2_.x - pos_tri_.x) * k;
  p2_.y = pos_tri_.y + (p2_.y - pos_tri_.y) * k;
  p3_.x = pos_tri_.x + (p3_.x - pos_tri_.x) * k;
  p3_.y = pos_tri_.y + (p3_.y - pos_tri_.y) * k;
}
