#include "parallelogram.hpp"

#include <stdexcept>

gladyshev::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3):
  p_{ p1, p2, p3 }
{
 if (!(((p_[0].y == p_[1].y) && (p_[1].y != p_[2].y) && (p_[0].x != p_[1].x)) || ((p_[1].y == p_[2].y) && (p_[2].y != p_[0].y) && (p_[1].x != p_[2].x))))
  {
    throw std::invalid_argument("bad parallelogram coords");
  }
}

gladyshev::Parallelogram::~Parallelogram() = default;

double gladyshev::Parallelogram::getArea() const
{
  return std::abs((p_[0].y - p_[2].y) * (std::max(std::abs(p_[0].x - p_[1].x), std::abs(p_[1].x - p_[2].x))));
}

gladyshev::rectangle_t gladyshev::Parallelogram::getFrameRect() const
{
  point_t p1FramePar_ = { std::min(p_[0].x, std::min(p_[1].x, std::min(p_[2].x, p_[0].x - p_[1].x + p_[2].x))), std::min(p_[0].y, p_[2].y) };
  point_t p2FramePar_ = { std::max(p_[0].x, std::max(p_[1].x, std::max(p_[2].x, p_[0].x - p_[1].x + p_[2].x))), std::max(p_[0].y, p_[2].y) };
  double width = std::abs(p1FramePar_.x - p2FramePar_.x);
  double height = std::abs(p1FramePar_.y - p2FramePar_.y);
  point_t pos = { (p1FramePar_.x + p2FramePar_.x) / 2, (p1FramePar_.y + p2FramePar_.y) / 2 };
  rectangle_t frameRect = { pos, width, height };
  return frameRect;
}

void gladyshev::Parallelogram::move(double dx, double dy)
{
  for (size_t i = 0; i < 3; ++i)
  {
    p_[i].x += dx;
    p_[i].y += dy;
  }
}

void gladyshev::Parallelogram::move(const point_t& newPos)
{
  move(newPos.x - getFrameRect().pos.x, newPos.y - getFrameRect().pos.y);
}

void gladyshev::Parallelogram::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::underflow_error("factor must be positive");
  }
  rectangle_t frameRect = getFrameRect();
  for (size_t i = 0; i < 3; ++i)
  {
    p_[i].x = p_[i].x - (frameRect.pos.x - p_[i].x) * (factor - 1);
    p_[i].y = p_[i].y - (frameRect.pos.y - p_[i].y) * (factor - 1);
  }
}
