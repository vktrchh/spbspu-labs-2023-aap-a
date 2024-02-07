#include "diamond.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "triangle.hpp"
#include "geom_func.hpp"

erohin::Diamond::Diamond() :
  frameRect_ {0.0, 0.0, { 0.0, 0.0 } }
{}

erohin::Diamond::Diamond(point_t* corner)
{
  frameRect_ = { 0.0, 0.0, { 0.0, 0.0 } };
  double * side = getSides(corner, 3);
  int max_ind = 0;
  for (int i = 0; i < 3; ++i)
  {
    if (side[i] >= side[max_ind])
    {
      max_ind = i;
    }
    if (corner[i].x == corner[(i + 1) % 3].x && corner[i].y != corner[(i + 1) % 3].y)
    {
      frameRect_.height = 2 * side[i];
    }
    if (corner[i].y == corner[(i + 1) % 3].y && corner[i].x != corner[(i + 1) % 3].x)
    {
      frameRect_.width = 2 * side[i];
    }
  }
  delete[] side;
  frameRect_.pos = corner[(max_ind + 2) % 3];
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
  if (ratio <= 0)
  {
    throw std::invalid_argument("Wrong scale ratio");
  }
  frameRect_.width *= ratio;
  frameRect_.height *= ratio;
}
