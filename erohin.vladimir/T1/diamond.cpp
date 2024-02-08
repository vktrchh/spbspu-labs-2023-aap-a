#include "diamond.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "triangle.hpp"
#include "geom_func.hpp"

erohin::Diamond::Diamond(point_t corner1, point_t corner2, point_t corner3) :
  frameRect_{ findDiamondFrameRect(corner1, corner2, corner3) }
{
  if (frameRect_.width * frameRect_.height == 0.0)
  {
    throw std::invalid_argument("Diamond sides are not parallel to the axes");
  }
}

erohin::Diamond::~Diamond() = default;

double erohin::Diamond::getArea() const
{
  return (frameRect_.width * frameRect_.height) / 2;
}

erohin::rectangle_t erohin::Diamond::getFrameRect() const
{
  return frameRect_;
}

void erohin::Diamond::move(double dx, double dy)
{
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
}

void erohin::Diamond::move(point_t point)
{
  frameRect_.pos = point;
}

void erohin::Diamond::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
  frameRect_.width *= ratio;
  frameRect_.height *= ratio;
}
