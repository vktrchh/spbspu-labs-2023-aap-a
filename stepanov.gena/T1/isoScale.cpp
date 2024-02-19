#include "isoScale.hpp"
#include <stdexcept>

void stepanov::isoScale(Shape* figure, point_t& p, double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Scaling ratio must be positive");
  }
  point_t center_old = figure->getFrameRect().center;
  figure->move(p);
  figure->scale(ratio);
  point_t new_center = figure->getFrameRect().center;
  double dx = (center_old.x - new_center.x) * ratio;
  double dy = (center_old.y - new_center.y) * ratio;
  figure->move(dx, dy);
}
