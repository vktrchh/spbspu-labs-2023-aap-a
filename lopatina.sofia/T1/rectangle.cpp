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

void lopatina::Rectangle::move(point_t s)
{
  pos_rect_.x_ = s.x_;
  pos_rect_.y_ = s.y_;
}

void lopatina::Rectangle::move(double x, double y)
{
  pos_rect_.x_ += x;
  pos_rect_.y_ += y;
}

lopatina::rectangle_t lopatina::Rectangle::scale(point_t s, double k)
{
  point_t point{pos_rect_.x_, pos_rect_.y_};
  move(s);
  height_rect_ = height_rect_ * k;
  width_rect_ = width_rect_ * k;
  move(k * (point.x_ - pos_rect_.x_), k * (point.y_ - pos_rect_.y_));
  rectangle_t newRect{height_rect_, width_rect_, pos_rect_};
  return newRect;
}
