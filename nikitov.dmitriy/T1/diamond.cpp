#include "diamond.hpp"
#include <cmath>
#include <stdexcept>

nikitov::Diamond::Diamond(const point_t& first, const point_t& second, const point_t& third):
  first_(first),
  second_(second),
  third_(third)
{
  size_t status = (first_.x - second_.x == 0 || first_.y - second_.y == 0);
  status += (first_.x - third_.x == 0 || first_.y - third_.y == 0);
  status += (second_.x - third_.x == 0 || second_.y - third_.y == 0);
  if (status < 2)
  {
    throw std::invalid_argument("Error: invalid diamond arguments");
  }

  point_t temp = first_;
  if (first_.x - second_.x == 0)
  {
    if (first_.y - third_.y != 0)
    {
      first_ = second_;
      second_ = temp;
    }
  }
  else if (first_.x - third_.x == 0)
  {
    if (first_.y - second_.x != 0)
    {
      first_ = third_;
      third_ = second_;
      second_ = temp;
    }
  }
  else
  {
    if (second_.y - first_.y == 0)
    {
      first_ = second_;
      second_ = third_;
      third_ = temp;
    }
    else
    {
      first_ = third_;
      third_ = temp;
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
  double width = std::abs(first_.x - third_.x) * 2;
  double height = std::abs(first_.y - second_.y) * 2;
  return { width, height, first_ };
}

void nikitov::Diamond::move(const point_t& point)
{
  double dx = point.x - first_.x;
  double dy = point.y - first_.y;
  move(dx, dy);
}

void nikitov::Diamond::move(double dx, double dy)
{
  first_.x += dx;
  first_.y += dy;
  second_.x += dx;
  second_.y += dy;
  third_.x += dx;
  third_.y += dy;
}

void nikitov::Diamond::scale(double ratio)
{
  second_.x = first_.x - (first_.x - second_.x) * ratio;
  second_.y = first_.y - (first_.y - second_.y) * ratio;
  third_.x = first_.x - (first_.x - third_.x) * ratio;
  third_.y = first_.y - (first_.y - third_.y) * ratio;
}
