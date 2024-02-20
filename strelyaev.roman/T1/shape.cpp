#include "shape.hpp"

strelyaev::Shape::scale(double k)
{
  if (k < 0)
  {
      std::logic_error("Invalid SCALE argument.");
  }
  doScale(k);
}
