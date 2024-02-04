#include <cmath>

#include "rectangle.hpp"

gladyshev::Rectangle::Rectangle(const point_t& p1, const point_t& p2):
  p1FrameRec_(p1),
  p2FrameRec_(p2)
{}

double gladyshev::Rectangle::getArea() const
{
  return std::abs((p2FrameRec_.x - p1FrameRec_.x) * (p2FrameRec_.y - p1FrameRec_.y));
}

void gladyshev::Rectangle::move(double dx, double dy)
{
  p1FrameRec_.x += dx;
  p2FrameRec_.x += dx;
  p1FrameRec_.y += dy;
  p2FrameRec_.y += dy;
}

void gladyshev::Rectangle::move(const point_t& newPos)
{
  move(newPos.x - getFrameRect().pos.x, newPos.y - getFrameRect().pos.y);
}

gladyshev::rectangle_t gladyshev::Rectangle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.height = std::abs(p1FrameRec_.y - p2FrameRec_.y);
  frameRect.width = std::abs(p1FrameRec_.x - p2FrameRec_.x);
  frameRect.pos = { (p1FrameRec_.x + p2FrameRec_.x) / 2, (p1FrameRec_.y + p2FrameRec_.y) / 2 };
  return frameRect;
}

void gladyshev::Rectangle::scale(double factor)
{
  rectangle_t frameRect = getFrameRect();
  p1FrameRec_.x = p1FrameRec_.x - (frameRect.pos.x - p1FrameRec_.x) * (factor - 1);
  p1FrameRec_.y = p1FrameRec_.y - (frameRect.pos.y - p1FrameRec_.y) * (factor - 1);
  p2FrameRec_.x = p2FrameRec_.x - (frameRect.pos.x - p2FrameRec_.x) * (factor - 1);
  p2FrameRec_.y = p2FrameRec_.y - (frameRect.pos.y - p2FrameRec_.y) * (factor - 1);
}
