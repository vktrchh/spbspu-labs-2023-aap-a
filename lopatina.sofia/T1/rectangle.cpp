#include "rectangle.hpp"
#include "base-types.hpp"
#include "shape.hpp"

lopatina::Rectangle::Rectangle(point_t a, point_t b)
{
  height_rect_ = b.y_ - a.y_;
  width_rect_ = b.x_ - a.x_;
  pos_rect_.x_ = (a.x_ + b.x_) / 2.0;
  pos_rect_.y_ = (a.y_ + b.y_) / 2.0;
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
  pos_rect_.x_ = new_pos.x_;
  pos_rect_.y_ = new_pos.y_;
}

void lopatina::Rectangle::move(double dx, double dy)
{
  pos_rect_.x_ += dx;
  pos_rect_.y_ += dy;
}

void lopatina::Rectangle::scale(point_t new_pos, double k)
{
  point_t old_pos{pos_rect_.x_, pos_rect_.y_};
  move(new_pos);
  height_rect_ = height_rect_ * k;
  width_rect_ = width_rect_ * k;
  move(k * (old_pos.x_ - pos_rect_.x_), k * (old_pos.y_ - pos_rect_.y_));
}
