#include "rectangle.hpp"
#include <stdexcept>
#include "pointLogic.hpp"

grechishnikov::Rectangle::Rectangle(const point_t* points, size_t size):
  points_(new point_t[size]),
  size_(size)
{
  if (size != 2)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (Wrong number of  arguments for rectangle)");
  }
  if (points[0].x >= points[1].x || points[0].y >= points[1].y)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (Points were entered incorrectly)");
  }
  for (size_t i = 0; i < size; i++)
  {
    points_[i] = points[i];
  }
}

grechishnikov::Rectangle::~Rectangle()
{
  delete[] points_;
}

double grechishnikov::Rectangle::getArea() const
{
  return (points_[1].x - points_[0].x) * (points_[1].y - points_[0].y);
}

grechishnikov::rectangle_t grechishnikov::Rectangle::getFrameRect() const
{
  return getFrameRectGeneral(points_, size_);
}

void grechishnikov::Rectangle::move(const point_t& pos)
{
  point_t aPos = getAveragePoint(points_, size_);
  double dx = pos.x - aPos.x;
  double dy = pos.y - aPos.y;
  move(dx, dy);
}

void grechishnikov::Rectangle::move(double dx, double dy)
{
  movePoints(points_, size_, dx, dy);
}

void grechishnikov::Rectangle::scale(double rate)
{
  scalePoints(points_, size_, rate);
}
