#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

lopatina::Triangle::Triangle(point_t point1, point_t point2, point_t point3):
  p1_(point1),
  p2_(point2),
  p3_(point3)
{
  double a = std::sqrt(std::pow(point1.x - point2.x, 2.0) + std::pow(point1.y - point2.y, 2.0));
  double b = std::sqrt(std::pow(point2.x - point3.x, 2.0) + std::pow(point2.y - point3.y, 2.0));
  double c = std::sqrt(std::pow(point1.x - point3.x, 2.0) + std::pow(point1.y - point3.y, 2.0));
  if ((a >= (b + c)) || (b >= (a + c)) || (c >= (a + b)))
  {
    throw std::invalid_argument("Figure has wrong parameter");
  }
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
  double height = max_y - min_y;
  double width = max_x - min_x;
  point_t pos = {min_x + (width / 2.0), min_y + (height / 2.0)};
  rectangle_t newRect{height, width, pos};
  return newRect;
}

void lopatina::Triangle::move(point_t new_pos)
{
  point_t pos_tri = {(p1_.x + p2_.x + p3_.x) / 3.0, (p1_.y + p2_.y + p3_.y) / 3.0};
  double dx = new_pos.x - pos_tri.x;
  double dy = new_pos.y - pos_tri.y;
  move(dx, dy);
}

void lopatina::Triangle::move(double dx, double dy)
{
  p1_.x += dx;
  p1_.y += dy;
  p2_.x += dx;
  p2_.y += dy;
  p3_.x += dx;
  p3_.y += dy;
}

void lopatina::Triangle::scale(double k)
{
  point_t pos_tri = {(p1_.x + p2_.x + p3_.x) / 3.0, (p1_.y + p2_.y + p3_.y) / 3.0};
  p1_.x = pos_tri.x + (p1_.x - pos_tri.x) * k;
  p1_.y = pos_tri.y + (p1_.y - pos_tri.y) * k;
  p2_.x = pos_tri.x + (p2_.x - pos_tri.x) * k;
  p2_.y = pos_tri.y + (p2_.y - pos_tri.y) * k;
  p3_.x = pos_tri.x + (p3_.x - pos_tri.x) * k;
  p3_.y = pos_tri.y + (p3_.y - pos_tri.y) * k;
}
