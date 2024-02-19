#include "diamond.hpp"
#include <cstddef>
#include <cmath>

lopatina::Diamond::Diamond(point_t central, point_t side_x, point_t side_y)
{
  height_diam_ = 2.0 * std::abs (side_y.y - central.y);
  width_diam_ = 2.0 * std::abs (side_x.x - central.x);
  pos_diam_.x = central.x;
  pos_diam_.y = central.y;
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
  pos_diam_.x = new_pos.x;
  pos_diam_.y = new_pos.y;
}

void lopatina::Diamond::move(double dx, double dy)
{
  pos_diam_.x += dx;
  pos_diam_.y += dy;
}

void lopatina::Diamond::scale(point_t new_pos, double k)
{
  point_t old_pos{pos_diam_.x, pos_diam_.y};
  move(new_pos);
  height_diam_ = height_diam_ * k;
  width_diam_ = width_diam_ * k;
  move(k * (old_pos.x - pos_diam_.x), k * (old_pos.y - pos_diam_.y));
}
