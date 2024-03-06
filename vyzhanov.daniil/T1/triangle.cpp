#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

double findAreaOfTri(const vyzhanov::point_t& a, const vyzhanov::point_t& b, const vyzhanov::point_t& c);

double findAreaOfTri(const vyzhanov::point_t& a, const vyzhanov::point_t& b, const vyzhanov::point_t& c)
{
  double sq = ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;
  sq = std::abs(sq);
  return sq;
}

vyzhanov::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  points_{ a, b, c },
  size_(3)
{
  if (findAreaOfTri(a, b, c) == 0)
  {
    throw std::invalid_argument("Invalid points");
  }
}

double vyzhanov::Triangle::getArea() const
{
  return findAreaOfTri(points_[0], points_[1], points_[2]);
}

vyzhanov::rectangle_t vyzhanov::Triangle::getFrameRect() const
{
  double height = (std::max(std::max(points_[0].y, points_[1].y), points_[2].y) - std::min(std::min(points_[0].y, points_[1].y), points_[2].y));
  double width = (std::max(std::max(points_[0].x, points_[1].x), points_[2].x) - std::min(std::min(points_[0].x, points_[1].x), points_[2].x));
  point_t pos = { std::min(std::min(points_[0].x, points_[1].x), points_[2].x) + width / 2, std::min(std::min(points_[0].y, points_[1].y), points_[2].y) + height / 2 };
  return { width, height, pos };
}
