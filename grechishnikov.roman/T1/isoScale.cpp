#include "isoScale.hpp"
#include <stdexcept>

void grechishnikov::isoScale(grechishnikov::Shape* shape, grechishnikov::point_t scalePoint, double ratio)
{
  if (ratio <= 0)
  {
    throw std::logic_error("Incorrect scale ratio");
  }
  if (shape != nullptr)
  {
    grechishnikov::point_t initPoint = shape->getFrameRect().pos;
    shape->move(scalePoint);
    grechishnikov::point_t isoPoint = shape->getFrameRect().pos;
    shape->scale(ratio);
    shape->move((initPoint.x - isoPoint.x) * ratio, (initPoint.y - isoPoint.y) * ratio);
  }
}
