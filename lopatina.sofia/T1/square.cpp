#include "square.hpp"
#include "base-types.hpp"

lopatina::Square::Square(point_t a, double side)
{
  side_ = side;
  pos_sq_.x_ = a.x_ + (side_ / 2.0);
  pos_sq_.y_ = a.y_ + (side_ / 2.0);
}

double lopatina::Square::getArea()
{
  return side_ * side_;
}

lopatina::rectangle_t lopatina::Square::getFrameRect()
{
  rectangle_t newRect{side_, side_, pos_sq_};
  return newRect;
}

void lopatina::Square::move(point_t s)
{
  pos_sq_.x_ = s.x_;
  pos_sq_.y_ = s.y_;
}

void lopatina::Square::move(double x, double y)
{
  pos_sq_.x_ += x;
  pos_sq_.y_ += y;
}

lopatina::rectangle_t lopatina::Square::scale(point_t s, double k)
{
  point_t point{pos_sq_.x_, pos_sq_.y_};
  move(s);
  side_ = side_ * k;
  move(k * (point.x_ - pos_sq_.x_), k * (point.y_ - pos_sq_.y_));
  rectangle_t newRect{side_, side_, pos_sq_};
  return newRect;
}
