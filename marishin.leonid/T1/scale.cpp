#include "scale.hpp"

void marishin::scale(Shape *shape, const point_t &center, double scaleCoefficient)
{
  if (scaleCoefficient <= 0.0)
  {
    throw std::invalid_argument("Invalid scale coefficient. Must be non-negative.");
  }

  point_t initialPosition = shape->getFrameRect().pos;
  shape->move(center);
  point_t newPosition = shape->getFrameRect().pos;
  shape->scale(scaleCoefficient);
  shape->move((initialPosition.x - newPosition.x) * scaleCoefficient, (initialPosition.y - newPosition.y) * scaleCoefficient);
}
