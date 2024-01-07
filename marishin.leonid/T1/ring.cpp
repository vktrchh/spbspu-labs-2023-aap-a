#include "ring.hpp"
#include <math.h>

Ring::Ring(point_t center, const double radius1, const double radius2):
  radius1_(radius1),
  radius2_(radius2),
  center_(center)
{
  if (radius1_ <= 0 || radius2_ <= 0 || radius1_ >= radius2_)
  {
    throw std::logic_error("Invalid ring");
  }
}
