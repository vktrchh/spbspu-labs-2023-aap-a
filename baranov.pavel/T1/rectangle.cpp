#include "rectangle.hpp"
#include <stdexcept>

baranov::Rectangle::Rectangle(const point_t & ldCorner, const point_t & ruCorner):
  ldCorner_(ldCorner),
  ruCorner_(ruCorner)
{
  if (ldCorner.x >= ruCorner.x || ldCorner.y >= ruCorner.y)
  {
    throw std::invalid_argument("Invalid rectangle parameters");
  }
}

