#include "triangle.hpp"
#include <cmath>
#include <algorithm>
#include "base-types.hpp"

lopatina::Triangle::Triangle(point_t point1, point_t point2, point_t point3)
{
  p1_.x_ = point1.x_;
  p1_.y_ = point1.y_;
  p2_.x_ = point2.x_;
  p2_.y_ = point2.y_;
  p3_.x_ = point3.x_;
  p3_.y_ = point3.y_;
  pos_tri_.x_ = (point1.x_ + point2.x_ + point3.x_) / 3.0;
  pos_tri_.y_ = (point1.y_ + point2.y_ + point3.y_) / 3.0;
  double max_x = std::max({point1.x_, point2.x_, point3.x_});
  double min_x = std::min({point1.x_, point2.x_, point3.x_});
  double max_y = std::max({point1.y_, point2.y_, point3.y_});
  double min_y = std::min({point1.y_, point2.y_, point3.y_});
  height_tri_ = max_y - min_y;
  width_tri_ = max_x - min_x;
  pos_.x_ = min_x + (width_tri_ / 2.0);
  pos_.y_ = min_y + (height_tri_ / 2.0);
}

double lopatina::Triangle::getArea()
{
  return 0.5 * (std::abs ((p2_.x_ - p1_.x_) * (p3_.y_ - p1_.y_) - (p3_.x_ - p1_.x_) * (p2_.y_ - p1_.y_)));
}

lopatina::rectangle_t lopatina::Triangle::getFrameRect()
{
  rectangle_t newRect{height_tri_, width_tri_, pos_};
  return newRect;
}

void lopatina::Triangle::move(point_t new_pos)
{
  double dx = new_pos.x_ - pos_tri_.x_;
  double dy = new_pos.y_ - pos_tri_.y_;
  move(dx, dy);
}

void lopatina::Triangle::move(double dx, double dy)
{
  pos_tri_.x_ += dx;
  pos_tri_.y_ += dy;
  pos_.x_ += dx;
  pos_.y_ += dy;
  p1_.x_ += dx;
  p1_.y_ += dy;
  p2_.x_ += dx;
  p2_.y_ += dy;
  p3_.x_ += dx;
  p3_.y_ += dy;
}

lopatina::rectangle_t lopatina::Triangle::scale(point_t new_pos, double k)
{
  point_t old_pos{pos_tri_.x_, pos_tri_.y_};
  move(new_pos);
  height_tri_ = height_tri_ * k;
  width_tri_ = width_tri_ * k;
  p1_.x_ = pos_tri_.x_ + (p1_.x_ - pos_tri_.x_) * k;
  p1_.y_ = pos_tri_.y_ + (p1_.y_ - pos_tri_.y_) * k;
  p2_.x_ = pos_tri_.x_ + (p2_.x_ - pos_tri_.x_) * k;
  p2_.y_ = pos_tri_.y_ + (p2_.y_ - pos_tri_.y_) * k;
  p3_.x_ = pos_tri_.x_ + (p3_.x_ - pos_tri_.x_) * k;
  p3_.y_ = pos_tri_.y_ + (p3_.y_ - pos_tri_.y_) * k;
  move(k * (old_pos.x_ - pos_tri_.x_), k * (old_pos.y_ - pos_tri_.y_));
  rectangle_t newRect{height_tri_, width_tri_, pos_};
  return newRect;
}
