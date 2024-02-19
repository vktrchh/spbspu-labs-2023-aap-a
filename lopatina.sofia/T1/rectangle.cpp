#include "rectangle.hpp"

lopatina::Rectangle::Rectangle(point_t a, point_t b)
{
  height_rect_ = b.y - a.y;
  width_rect_ = b.x - a.x;
  pos_rect_.x = (a.x + b.x) / 2.0;
  pos_rect_.y = (a.y + b.y) / 2.0;
}

double lopatina::Rectangle::getArea()
{
  return height_rect_ * width_rect_;
}

lopatina::rectangle_t lopatina::Rectangle::getFrameRect()
{
  rectangle_t newRect{height_rect_, width_rect_, pos_rect_};
  return newRect;
}

void lopatina::Rectangle::move(point_t new_pos)
{
  pos_rect_.x = new_pos.x;
  pos_rect_.y = new_pos.y;
}

void lopatina::Rectangle::move(double dx, double dy)
{
  pos_rect_.x += dx;
  pos_rect_.y += dy;
}

void lopatina::Rectangle::scale(point_t new_pos, double k)
{
  point_t old_pos{pos_rect_.x, pos_rect_.y};
  move(new_pos);
  height_rect_ = height_rect_ * k;
  width_rect_ = width_rect_ * k;
  move(k * (old_pos.x - pos_rect_.x), k * (old_pos.y - pos_rect_.y));
}
