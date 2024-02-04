#include <cmath>

#include "circle.hpp"

gladyshev::Circle::Circle(const point_t& p1, double radius):
  radiuscircle_{ radius },
  p1FrameCir_{ p1.x - radius, p1.y - radius },
  p2FrameCir_{ p1.x + radius, p1.y + radius }
{}

double gladyshev::Circle::getArea() const
{
  return (radiuscircle_ * radiuscircle_ * 3.14);
}

gladyshev::rectangle_t gladyshev::Circle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.height = std::abs(p1FrameCir_.y - p2FrameCir_.y);
  frameRect.width = std::abs(p1FrameCir_.x - p2FrameCir_.x);
  frameRect.pos = { (p1FrameCir_.x + p2FrameCir_.x) / 2, (p1FrameCir_.y + p2FrameCir_.y) / 2 };
  return frameRect;
}

void gladyshev::Circle::move(double dx, double dy)
{
  p1FrameCir_.x += dx;
  p2FrameCir_.x += dx;
  p1FrameCir_.y += dy;
  p2FrameCir_.y += dy;
}
void gladyshev::Circle::move(const point_t& newPos)
{
  move(newPos.x - getFrameRect().pos.x, newPos.y - getFrameRect().pos.y);
}

void gladyshev::Circle::scale(double factor)
{
  rectangle_t frameRect = getFrameRect();
  p1FrameCir_.x = p1FrameCir_.x - (frameRect.pos.x - p1FrameCir_.x) * (factor - 1);
  p1FrameCir_.y = p1FrameCir_.y - (frameRect.pos.y - p1FrameCir_.y) * (factor - 1);
  p2FrameCir_.x = p2FrameCir_.x - (frameRect.pos.x - p2FrameCir_.x) * (factor - 1);
  p2FrameCir_.y = p2FrameCir_.y - (frameRect.pos.y - p2FrameCir_.y) * (factor - 1);
}
