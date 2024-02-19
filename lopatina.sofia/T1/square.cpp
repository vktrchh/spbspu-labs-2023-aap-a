#include "square.hpp"

lopatina::Square::Square(point_t a, double side)
{
  side_ = side;
  pos_sq_.x = a.x + (side_ / 2.0);
  pos_sq_.y = a.y + (side_ / 2.0);
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
  pos_sq_.x = new_pos.x;
  pos_sq_.y = new_pos.y;
}

void lopatina::Square::move(double dx, double dy)
{
  pos_sq_.x += dx;
  pos_sq_.y += dy;
}

void lopatina::Square::scale(point_t new_pos, double k)
{
  point_t old_pos{pos_sq_.x, pos_sq_.y};
  move(new_pos);
  side_ = side_ * k;
  move(k * (old_pos.x - pos_sq_.x), k * (old_pos.y - pos_sq_.y));
}
