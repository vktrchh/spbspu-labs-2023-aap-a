#include "shape.hpp"

#include <stdexcept>

void zhalilov::Shape::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::underflow_error("scale ratio should be more than zero");
  }
  unsafeScale(ratio);
}
