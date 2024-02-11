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
    shape->scale(ratio);
    shape->move((initPoint.x - scalePoint.x) * ratio, (initPoint.y - scalePoint.y) * ratio);
  }
}
