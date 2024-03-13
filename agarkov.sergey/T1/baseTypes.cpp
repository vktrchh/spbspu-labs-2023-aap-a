#include "baseTypes.hpp"

void agarkov::point_t::move(double dx, double dy)
{
  x_ += dx;
  y_ += dy;
}
