#include <cmath>
#include <algorithm>
#include "triangle.hpp"
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

void lopatina::Triangle::move(point_t s)
{
  pos_tri_.x_ = s.x_;
  pos_tri_.y_ = s.y_;
}

void lopatina::Triangle::move(double x, double y)
{
  pos_.x_ += x;
  pos_.y_ += y;
  p1_.x_ += x;
  p1_.y_ += y;
  p2_.x_ += x;
  p2_.y_ += y;
  p3_.x_ += x;
  p3_.y_ += y;
}

lopatina::rectangle_t lopatina::Triangle::scale(point_t s, double k)
{
  point_t point{pos_tri_.x_, pos_tri_.y_};
  move(s);
  height_tri_ = height_tri_ * k;
  width_tri_ = width_tri_ * k;
  move(k * (point.x_ - pos_tri_.x_), k * (point.y_ - pos_tri_.y_));
  rectangle_t newRect{height_tri_, width_tri_, pos_};
  return newRect;
}
