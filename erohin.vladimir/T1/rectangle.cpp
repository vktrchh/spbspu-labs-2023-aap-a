#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "geom_func.hpp"

erohin::Rectangle::Rectangle(point_t left_lower_corner, point_t right_upper_corner):
  frameRect_{ findRectangleFrameRect(left_lower_corner, right_upper_corner) }
{
  if (left_lower_corner.x >= right_upper_corner.x || left_lower_corner.y >= right_upper_corner.y)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
}

erohin::Rectangle::~Rectangle() = default;

double erohin::Rectangle::getArea() const
{
  return (frameRect_.width * frameRect_.height);
}

erohin::rectangle_t erohin::Rectangle::getFrameRect() const
{
  return frameRect_;
}

void erohin::Rectangle::move(double dx, double dy)
{
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
}

void erohin::Rectangle::move(point_t point)
{
  frameRect_.pos = point;
}

erohin::Shape* erohin::Rectangle::clone() const
{
  point_t corner[2] = { 0.0, 0.0 };
  rectangle_t framRect = getFrameRect();
  corner[0].x = framRect.pos.x - framRect.width / 2.0;
  corner[0].y = framRect.pos.y - framRect.height / 2.0;
  corner[1].x = framRect.pos.x + framRect.width / 2.0;
  corner[1].y = framRect.pos.y + framRect.height / 2.0;
  Shape* shape = new Rectangle(corner[0], corner[1]);
  return shape;
}

void erohin::Rectangle::doScaling(double ratio)
{
  frameRect_.width *= ratio;
  frameRect_.height *= ratio;
}
