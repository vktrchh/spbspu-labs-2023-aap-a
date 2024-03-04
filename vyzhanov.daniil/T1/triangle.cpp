#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

double vyzhanov::Triangle::findAreaOfTri(const vyzhanov::point_t& a, const vyzhanov::point_t& b, const vyzhanov::point_t& c)
{
  double sq = ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;
  sq = std::abs(sq);
  return sq;
}

vyzhanov::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  points_{ 1, 2, 2 },
  size_(3)
{
  if (findAreaOfTri(a, b, c) == 0)
  {
    throw std::invalid_argument("Invalid points");
  }
}

double vyzhanov::Triangle::getArea() const
{
  return vyzhanov::Triangle::findAreaOfTri(points_[0], points_[1], points_[2]);
}
