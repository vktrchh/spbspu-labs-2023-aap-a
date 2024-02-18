#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "pointLogic.hpp"

grechishnikov::Triangle::Triangle(const point_t* points, size_t size):
  points_(new point_t[size]),
  size_(size)
{
  if (size != 3)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (Wrong number of  arguments for triangle)");
  }
  for (size_t i = 0; i < size; i++)
  {
    points_[i] = points[i];
  }
  if (this->getArea() == 0)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (Points were entered incorrectly)");
  }
}

grechishnikov::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  points_(new point_t[3] { a, b, c }),
  size_(3)
{
  if (this->getArea() == 0)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (Points don't form a triangle)");
  }
}

grechishnikov::Triangle::~Triangle()
{
  delete[] points_;
}

double grechishnikov::Triangle::getArea() const
{
  double sq = ((points_[1].x - points_[0].x) * (points_[2].y - points_[0].y)
     - (points_[2].x - points_[0].x) * (points_[1].y - points_[0].y)) / 2;
  sq = std::abs(sq);
  return sq;
}

grechishnikov::rectangle_t grechishnikov::Triangle::getFrameRect() const
{
  return getFrameRectGeneral(points_, 3);
}

void grechishnikov::Triangle::move(const point_t& pos)
{
  point_t aPos = getAveragePoint(points_, 3);
  move(pos.x - aPos.x, pos.y - aPos.y);
}

void grechishnikov::Triangle::move(double dx, double dy)
{
  movePoints(points_, size_, dx, dy);
}

void grechishnikov::Triangle::scale(double rate)
{
  scalePoints(points_, size_, rate);
}
