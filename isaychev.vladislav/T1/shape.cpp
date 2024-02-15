#include "shape.hpp"
#include <stdexcept>

void isaychev::Shape::doScale(double coeff)
{
  if (coeff <= 0.0)
  {
    throw std::invalid_argument("wrong coefficient for scale");
  }
  scale(coeff);
}
