#include "rectangle.hpp"
#include "figureFunction.hpp"

#include <stdexcept>

rebdev::Rectangle::Rectangle(const point_t & firstAngle, const point_t & secondAngle):
  angles_{{0.0, 0.0}, {0.0, 0.0}}
{
  if ((firstAngle.x >= secondAngle.x) || (firstAngle.y >= secondAngle.y))
  {
    throw std::logic_error("rectangle error");
  }
  angles_[0] = firstAngle;
  angles_[1] = secondAngle;
}

double rebdev::Rectangle::getArea() const
{
  return ((angles_[1].x - angles_[0].x) * (angles_[1].y - angles_[0].y));
}

rebdev::rectangle_t rebdev::Rectangle::getFrameRect() const
{
  return getFrameRectangle(angles_, 2);
}

void rebdev::Rectangle::move(const point_t & point)
{
  rectangle_t frameRectangle = getFrameRect();
  move(point.x - frameRectangle.pos.x, point.y - frameRectangle.pos.y);
}

void rebdev::Rectangle::move(double x, double y)
{
  angles_[0].x += x;
  angles_[0].y += y;
  angles_[1].x += x;
  angles_[1].y += y;
}

void rebdev::Rectangle::scale(double k)
{
  scaleFigure(angles_, 2, getFrameRect().pos, k);
}
