#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

nikitov::Diamond::Diamond(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  size_t status = (firstPoint_.x - secondPoint_.x == 0 || firstPoint_.y - secondPoint_.y == 0);
  status += (firstPoint_.x - thirdPoint_.x == 0 || firstPoint_.y - thirdPoint_.y == 0);
  status += (secondPoint_.x - thirdPoint_.x == 0 || secondPoint_.y - thirdPoint_.y == 0);
  if (status < 2)
  {
    throw std::invalid_argument("Error: invalid diamond arguments");
  }

  point_t temp = firstPoint_;
  if (firstPoint_.x - secondPoint_.x == 0)
  {
    if (firstPoint_.y - thirdPoint_.y != 0)
    {
      firstPoint_ = secondPoint_;
      secondPoint_ = temp;
    }
  }
  else if (firstPoint_.x - thirdPoint_.x == 0)
  {
    if (firstPoint_.y - secondPoint_.x != 0)
    {
      firstPoint_ = thirdPoint_;
      thirdPoint_ = secondPoint_;
      secondPoint_ = temp;
    }
  }
  else
  {
    if (secondPoint_.y - firstPoint_.y == 0)
    {
      firstPoint_ = secondPoint_;
      secondPoint_ = thirdPoint_;
      thirdPoint_ = temp;
    }
    else
    {
      firstPoint_ = thirdPoint_;
      thirdPoint_ = temp;
    }
  }
}

double nikitov::Diamond::getArea() const
{
  rectangle_t frame = getFrameRect();
  return frame.width * frame.height / 2;
}

nikitov::rectangle_t nikitov::Diamond::getFrameRect() const
{
  double width = abs(firstPoint_.x - thirdPoint_.x) * 2;
  double height = abs(firstPoint_.y - secondPoint_.y) * 2;
  return { width, height, firstPoint_ };
}

void nikitov::Diamond::move(const point_t& point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void nikitov::Diamond::move(double dx, double dy)
{
  firstPoint_.x += dx;
  firstPoint_.y += dy;
  secondPoint_.x += dx;
  secondPoint_.y += dy;
  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}

void nikitov::Diamond::scale(double ratio)
{
  secondPoint_.x = firstPoint_.x - (firstPoint_.x - secondPoint_.x) * ratio;
  secondPoint_.y = firstPoint_.y - (firstPoint_.y - secondPoint_.y) * ratio;
  thirdPoint_.x = firstPoint_.x - (firstPoint_.x - thirdPoint_.x) * ratio;
  thirdPoint_.y = firstPoint_.y - (firstPoint_.y - thirdPoint_.y) * ratio;
}
