#include "ellipse.hpp"
#include <stdexcept>

stepanov::Ellipse::Ellipse(const point_t &center, double radiusY, double radiusX):
  center_(center),
  radiusY_(radiusY),
  radiusX_(radiusX)
{
  if ((radiusY <= 0.0) || (radiusX <= 0.0))
  {
    throw std::invalid_argument("Radius must be positive")
  }
}

double stepanov::Ellipse::getArea() const
{
  return 3.14 * radiusY_ * radiusX_;
}

stepanov::rectangle_t stepanov::Ellipse::getFrameRect() const
{
  return (2 * radiusX_, 2 * radiusY_, cenetr_))
}

