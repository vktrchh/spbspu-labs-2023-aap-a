#ifndef SCALERECTANGLE_HPP
#define SCALERECTANGLE_HPP

#include "base-types.hpp"

namespace marishin
{
  point_t mixPoint(point_t corner, double dx, double dy);
  point_t scalePoint(marishin::point_t corner, marishin::point_t pos, double factor);
}

#endif
