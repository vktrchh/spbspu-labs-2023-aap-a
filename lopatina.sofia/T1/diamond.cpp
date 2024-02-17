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

void lopatina::Diamond::move(point_t new_pos)
{
  pos_diam_.x_ = new_pos.x_;
  pos_diam_.y_ = new_pos.y_;
}

void lopatina::Diamond::move(double dx, double dy)
{
  pos_diam_.x_ += dx;
  pos_diam_.y_ += dy;
}

void lopatina::Diamond::scale(point_t new_pos, double k)
{
  point_t old_pos{pos_diam_.x_, pos_diam_.y_};
  move(new_pos);
  height_diam_ = height_diam_ * k;
  width_diam_ = width_diam_ * k;
  move(k * (old_pos.x_ - pos_diam_.x_), k * (old_pos.y_ - pos_diam_.y_));
}
