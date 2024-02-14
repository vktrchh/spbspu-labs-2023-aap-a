#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

grechishnikov::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  a_(a),
  b_(b),
  c_(c)
{
  double sq = this->getArea();
  if (sq == 0)
  {
    throw std::invalid_argument("Invalid parameters (Not a triangle)");
  }
}

double grechishnikov::Triangle::getArea() const
{
  double sq = ((b_.x - a_.x) * (c_.y - a_.y) - (c_.x - a_.x) * (b_.y - a_.y)) / 2;
  sq = std::abs(sq);
  return sq;
}

grechishnikov::rectangle_t grechishnikov::Triangle::getFrameRect() const
{
  double max_x = std::max( { a_.x, b_.x, c_.x } );
  double max_y = std::max( { a_.y, b_.y, c_.y } );
  double min_x = std::min( { a_.x, b_.x, c_.x } );
  double min_y = std::min( { a_.y, b_.y, c_.y } );
  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos = { min_x + width / 2.0, min_y + height / 2.0 };
  return { width, height, pos };
}

void grechishnikov::Triangle::move(const point_t& pos)
{
  point_t aPos = { (a_.x + b_.x + c_.x) / 3.0, (a_.y + b_.y + c_.y) / 3.0 };
  move(pos.x - aPos.x, pos.y - aPos.y);
}

void grechishnikov::Triangle::move(double dx, double dy)
{
  a_.x += dx;
  b_.x += dx;
  c_.x += dx;
  a_.y += dy;
  b_.y += dy;
  c_.y += dy;
}

void grechishnikov::Triangle::scale(double rate)
{
  point_t aPos = { (a_.x + b_.x + c_.x) / 3.0, (a_.y + b_.y + c_.y) / 3.0 };
  a_.x = aPos.x + (a_.x - aPos.x) * rate;
  a_.y = aPos.y + (a_.y - aPos.y) * rate;
  b_.x = aPos.x + (b_.x - aPos.x) * rate;
  b_.y = aPos.y + (b_.y - aPos.y) * rate;
  c_.x = aPos.x + (c_.x - aPos.x) * rate;
  c_.y = aPos.y + (c_.y - aPos.y) * rate;
}
