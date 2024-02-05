#include "circle.hpp"

gladyshev::Circle::Circle(const point_t& p1, double radius):
  radiusCircle_{ radius },
  poscir_{ p1 }
{}

gladyshev::Circle::~Circle()
{}

double gladyshev::Circle::getArea() const
{
  return radiusCircle_ * radiusCircle_ * 3.14;
}

gladyshev::rectangle_t gladyshev::Circle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.height = 2 * radiusCircle_;
  frameRect.width = 2 * radiusCircle_;
  frameRect.pos = { poscir_.x, poscir_.y };
  return frameRect;
}

void gladyshev::Circle::move(double dx, double dy)
{
  poscir_.x += dx;
  poscir_.y += dy;
}
void gladyshev::Circle::move(const point_t& newPos)
{
  move(newPos.x - getFrameRect().pos.x, newPos.y - getFrameRect().pos.y);
}

void gladyshev::Circle::scale(double factor)
{
  radiusCircle_ *= factor;
}
