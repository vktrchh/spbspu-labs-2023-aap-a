#include "rectangle.hpp"
#include "base-types.hpp"

#include <stdexcept>

belokurskaya::Rectangle::Rectangle(const point_t & pos, double width, double height):
pos_(pos), width_(width), height_(height)
{
  if (width <= 0 || height <= 0)
  {
    throw std::invalid_argument("Invalid rectangle dimensions");
  }
}

double belokurskaya::Rectangle::getArea() const
{
  return width_ * height_;
}

belokurskaya::rectangle_t belokurskaya::Rectangle::getFrameRect() const
{
  return {pos_, width_, height_};
}

void belokurskaya::Rectangle::move(const point_t & new_pos)
{
  pos_ = new_pos;
}

void belokurskaya::Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void belokurskaya::Rectangle::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Invalid scaling factor");
  }

  width_ *= factor;
  height_ *= factor;
}
