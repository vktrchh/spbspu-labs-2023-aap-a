#include "shape.hpp"
#include <stdexcept>

void strelyaev::Shape::scale(double k)
{
  if (k < 0)
  {
    std::logic_error("Invalid SCALE argument.");
  }
  doScale(k);
}
