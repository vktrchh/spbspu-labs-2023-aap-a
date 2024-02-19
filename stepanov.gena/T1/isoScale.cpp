#include "iso_scale.hpp"
#include <stdexcept>

void stepanov::isoScale(const point_t& p, double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Scaling ratio must be positive")
  }
}
