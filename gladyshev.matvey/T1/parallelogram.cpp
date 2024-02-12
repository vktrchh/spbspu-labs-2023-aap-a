#include <algorithm>

#include "parallelogram.hpp"

gladyshev::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3):
  p1_(p1),
  p2_(p2),
  p3_(p3)
{}

gladyshev::Parallelogram::~Parallelogram()
{}

double gladyshev::Parallelogram::getArea() const
{
  return std::abs((p1_.y - p3_.y) * (std::max(std::abs(p1_.x - p2_.x), std::abs(p2_.x - p3_.x))));
}

gladyshev::rectangle_t gladyshev::Parallelogram::getFrameRect() const
{
  point_t p1FramePar_ = { std::min(p1_.x, std::min(p2_.x, std::min(p3_.x, p1_.x - p2_.x + p3_.x))), std::min(p1_.y, p3_.y) };
  point_t p2FramePar_ = { std::max(p1_.x, std::max(p2_.x, std::max(p3_.x, p1_.x - p2_.x + p3_.x))), std::max(p1_.y, p3_.y) };
  double width = std::abs(p1FramePar_.x - p2FramePar_.x);
  double height = std::abs(p1FramePar_.y - p2FramePar_.y);
  point_t pos = { (p1FramePar_.x + p2FramePar_.x) / 2, (p1FramePar_.y + p2FramePar_.y) / 2 };
  rectangle_t frameRect = { pos, width, height };
  return frameRect;
}

void gladyshev::Parallelogram::move(double dx, double dy)
{
  point_t * points[] = { &p1_, &p2_, &p3_ };
  for (size_t i = 0; i < 3; ++i)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void gladyshev::Parallelogram::move(const point_t& newPos)
{
  move(newPos.x - getFrameRect().pos.x, newPos.y - getFrameRect().pos.y);
}

void gladyshev::Parallelogram::scale(double factor)
{
  point_t * points[] = { &p1_, &p2_, &p3_ };
  rectangle_t frameRect = getFrameRect();
  for (size_t i = 0; i < 3; ++i)
  {
    points[i]->x = points[i]->x - (frameRect.pos.x - points[i]->x) * (factor - 1);
    points[i]->y = points[i]->y - (frameRect.pos.y - points[i]->y) * (factor - 1);
  }
}
