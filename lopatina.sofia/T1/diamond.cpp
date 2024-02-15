#include "diamond.hpp"
#include <iostream>
#include <cmath>
#include "base-types.hpp"

lopatina::Diamond::Diamond(point_t central, point_t side_x, point_t side_y)
{
  height_diam_ = std::abs (side_y.y_ - central.y_);
  width_diam_ = std::abs (side_x.x_ - central.x_);
  pos_diam_.x_ = central.x_;
  pos_diam_.y_ = central.y_;
}

double lopatina::Diamond::getArea()
{
  return (height_diam_ * width_diam_) / 2.0;
}

lopatina::rectangle_t lopatina::Diamond::getFrameRect()
{
  rectangle_t newRect{height_diam_, width_diam_, pos_diam_};
  return newRect;
}

void lopatina::Diamond::move(point_t s)
{
  pos_diam_.x_ = s.x_;
  pos_diam_.y_ = s.y_;
}

void lopatina::Diamond::move(double x, double y)
{
  pos_diam_.x_ += x;
  pos_diam_.y_ += y;
}

lopatina::rectangle_t lopatina::Diamond::scale(point_t s, double k)
{
  point_t point{pos_diam_.x_, pos_diam_.y_};
  move(s);
  height_diam_ = height_diam_ * k;
  width_diam_ = width_diam_ * k;
  move(k * (point.x_ - pos_diam_.x_), k * (point.y_ - pos_diam_.y_));
  rectangle_t newRect{ height_diam_, width_diam_, pos_diam_ };
  return newRect;
}
