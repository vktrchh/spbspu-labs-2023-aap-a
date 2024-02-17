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

void lopatina::Square::move(point_t new_pos)
{
  pos_sq_.x_ = new_pos.x_;
  pos_sq_.y_ = new_pos.y_;
}

void lopatina::Square::move(double dx, double dy)
{
  pos_sq_.x_ += dx;
  pos_sq_.y_ += dy;
}

void lopatina::Square::scale(point_t new_pos, double k)
{
  point_t old_pos{pos_sq_.x_, pos_sq_.y_};
  move(new_pos);
  side_ = side_ * k;
  move(k * (old_pos.x_ - pos_sq_.x_), k * (old_pos.y_ - pos_sq_.y_));
}
