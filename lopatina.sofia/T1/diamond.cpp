#include "diamond.hpp"
#include <cstddef>
#include <cmath>

lopatina::Diamond::Diamond(point_t central, point_t side_x, point_t side_y):
  central_vertex_(central),
  side_x_vertex_(side_x),
  side_y_vertex_(side_y)
{}

double lopatina::Diamond::getArea() const
{
  double diagonal_1 = 2.0 * std::abs(side_y_vertex_.y - central_vertex_.y);
  double diagonal_2 = 2.0 * std::abs(side_x_vertex_.x - central_vertex_.x);
  return diagonal_1 * diagonal_2 / 2.0;
}

lopatina::rectangle_t lopatina::Diamond::getFrameRect() const
{
  double height = 2.0 * std::abs(side_y_vertex_.y - central_vertex_.y);
  double width = 2.0 * std::abs(side_x_vertex_.x - central_vertex_.x);
  rectangle_t newRect{height, width, central_vertex_};
  return newRect;
}

void lopatina::Diamond::move(point_t new_pos)
{
  double dx = new_pos.x - central_vertex_.x;
  double dy = new_pos.y - central_vertex_.y;
  move(dx, dy);
}

void lopatina::Diamond::move(double dx, double dy)
{
  central_vertex_.x += dx;
  central_vertex_.y += dy;
  side_x_vertex_.x += dx;
  side_x_vertex_.y += dy;
  side_y_vertex_.x += dx;
  side_y_vertex_.y += dy;
}

void lopatina::Diamond::scale(double k)
{
  side_x_vertex_.x = central_vertex_.x + (side_x_vertex_.x - central_vertex_.x) * k;
  side_x_vertex_.y = central_vertex_.y + (side_x_vertex_.y - central_vertex_.y) * k;
  side_y_vertex_.x = central_vertex_.x + (side_y_vertex_.x - central_vertex_.x) * k;
  side_y_vertex_.y = central_vertex_.y + (side_y_vertex_.y - central_vertex_.y) * k;
}
