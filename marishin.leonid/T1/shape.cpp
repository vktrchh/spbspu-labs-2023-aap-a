#include "shape.hpp"
#include <stdexcept>

void marishin::Shape::checkScale(double factor)
{
  if (factor < 0.0)
  {
    throw std::invalid_argument("The coefficient must be positive");
  }
  scale(factor);
}
