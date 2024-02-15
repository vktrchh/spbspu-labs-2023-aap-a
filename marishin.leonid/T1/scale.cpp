#include "scale.hpp"

void marishin::scale(Shape *shape, point_t center, double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Invalid scale coefficient. Must be non-negative.");
  }

  point_t initialPosition = shape->getFrameRect().pos;
  shape->move(center);
  point_t newPosition = shape->getFrameRect().pos;
  shape->scale(coefficient);
  shape->move((initialPosition.x - newPosition.x) * coefficient, (initialPosition.y - newPosition.y) * coefficient);
}
