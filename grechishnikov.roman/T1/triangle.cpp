#include "triangle.hpp"
#include <stdexcept>

double max(double a, double b, double c);
double min(double a, double b, double c);

grechishnikov::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  a_(a),
  b_(b),
  c_(c)
{
  double sq = ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;
  if (sq == 0)
  {
    throw std::invalid_argument("Invalid parameters (Not a triangle)");
  }
}

grechishnikov::Triangle::Triangle():
  a_( { 0.0, 0.0 } ),
  b_( { 0.0, 0.0 } ),
  c_( { 0.0, 0.0 } )
{}


double grechishnikov::Triangle::getArea() const
{
  double sq = ((b_.x - a_.x) * (c_.y - a_.y) - (c_.x - a_.x) * (b_.y - a_.y)) / 2;
  if (sq < 0)
  {
    sq *= -1;
  }
  return sq;
}

grechishnikov::rectangle_t grechishnikov::Triangle::getFrameRect() const
{
  double max_x = max(a_.x, b_.x, c_.x);
  double max_y = max(a_.y, b_.y, c_.y);
  double min_x = min(a_.x, b_.x, c_.x);
  double min_y = min(a_.y, b_.y, c_.y);
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

double max(double a, double b, double c)
{
  double max = a;
  if (max < b)
  {
    max = b;
  }
  if (max < c)
  {
    max = c;
  }
  return max;
}

double min(double a, double b, double c)
{
  double min = a;
  if (min > b)
  {
    min = b;
  }
  if (min > c)
  {
    min = c;
  }
  return min;
}
