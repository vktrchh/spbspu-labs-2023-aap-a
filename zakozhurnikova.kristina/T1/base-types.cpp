#include "base-types.hpp"

void point_t::operator+=(const point_t& p)
{
  x_ += p.x_;
  y_ += p.y_;
}

void point_t::operator-=(const point_t& p)
{
  x_ -= p.x_;
  y_ -= p.y_;
}

point_t point_t::operator+(const point_t& p) const
{
  return point_t(x_ + p.x_, y_ + p.y_);
}

point_t point_t::operator-(const point_t& p) const
{
  return point_t(x_ - p.x_, y_ - p.y_);
}

