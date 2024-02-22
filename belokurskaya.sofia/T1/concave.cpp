#include "concave.hpp"

#include <stdexcept>
#include <cmath>

#include "shape.hpp"

belokurskaya::Concave::Concave(const point_t & a, const point_t & b, const point_t & c, const point_t & d):
  a_(a), b_(b), c_(c), d_(d)
{
  if (isTriangle(a_, b_, c_))
  {
    if (!isInsideTriangle(a_, b_, c_, d_))
    {
      throw std::invalid_argument("Fourth vertex must be inside the triangle formed by the first three vertices");
    }
    if (!isConcave(a_, b_, c_, d_))
    {
      throw std::invalid_argument("The vertices do not form a concave quadrilateral");
    }
  }
  else
  {
    throw std::invalid_argument("The first three vertices do not form a triangle");
  }
}

double belokurskaya::Concave::getArea() const
{
  double triangle1_area = calculateTriangleArea(a_, b_, d_);
  double triangle2_area = calculateTriangleArea(a_, c_, d_);
  return triangle1_area + triangle2_area;
}

belokurskaya::rectangle_t belokurskaya::Concave::getFrameRect() const
{
  double min_x = std::min(std::min(std::min(a_.x, b_.x), c_.x), d_.x);
  double min_y = std::min(std::min(std::min(a_.y, b_.y), c_.y), d_.y);
  double max_x = std::max(std::max(std::max(a_.x, b_.x), c_.x), d_.x);
  double max_y = std::max(std::max(std::max(a_.y, b_.y), c_.y), d_.y);
  point_t center = {(min_x + max_x) / 2, (min_y + max_y) / 2};
  return {center, max_x - min_x, max_y - min_y};
}

void belokurskaya::Concave::move(const point_t & new_pos)
{
  double dx = new_pos.x - getFrameRect().pos.x;
  double dy = new_pos.y - getFrameRect().pos.y;
  move(dx, dy);
}

void belokurskaya::Concave::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
  d_.x += dx;
  d_.y += dy;
}

void belokurskaya::Concave::scale(double factor)
{
  point_t center = calculateCentroid();

  a_ = {center.x + factor * (a_.x - center.x), center.y + factor * (a_.y - center.y)};
  b_ = {center.x + factor * (b_.x - center.x), center.y + factor * (b_.y - center.y)};
  c_ = {center.x + factor * (c_.x - center.x), center.y + factor * (c_.y - center.y)};
  d_ = {center.x + factor * (d_.x - center.x), center.y + factor * (d_.y - center.y)};
}

bool belokurskaya::Concave::isTriangle(const point_t & p1, const point_t & p2, const point_t & p3) const
{
  return ((p1.x - p2.x) * (p3.y - p2.y) - (p1.y - p2.y) * (p3.x - p2.x)) != 0;
}

bool belokurskaya::Concave::isInsideTriangle(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4) const
{
  double a = ((p2.y - p3.y) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.y - p3.y));
  double b = ((p2.y - p3.y) * (p4.x - p3.x) + (p3.x - p2.x) * (p4.y - p3.y));
  double c = ((p3.y - p1.y) * (p2.x - p1.x) + (p1.x - p3.x) * (p2.y - p1.y));
  double d = ((p3.y - p1.y) * (p4.x - p1.x) + (p1.x - p3.x) * (p4.y - p1.y));
  double e = ((p1.y - p2.y) * (p3.x - p2.x) + (p2.x - p1.x) * (p3.y - p2.y));
  double f = ((p1.y - p2.y) * (p4.x - p2.x) + (p2.x - p1.x) * (p4.y - p2.y));

  return a * b >= 0 && c * d >= 0 && e * f >= 0;
}

bool belokurskaya::Concave::isConcave(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4)
{
  double cross_product1 = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
  double cross_product2 = (p3.x - p2.x) * (p4.y - p2.y) - (p3.y - p2.y) * (p4.x - p2.x);
  double cross_product3 = (p4.x - p3.x) * (p1.y - p3.y) - (p4.y - p3.y) * (p1.x - p3.x);
  double cross_product4 = (p1.x - p4.x) * (p2.y - p4.y) - (p1.y - p4.y) * (p2.x - p4.x);

  int sign_changes = 0;
  if ((cross_product1 > 0) != (cross_product2 > 0))
  {
    sign_changes++;
  }
  if ((cross_product2 > 0) != (cross_product3 > 0))
  {
    sign_changes++;
  }
  if ((cross_product3 > 0) != (cross_product4 > 0))
  {
    sign_changes++;
  }
  if ((cross_product4 > 0) != (cross_product1 > 0))
  {
    sign_changes++;
  }
  return sign_changes > 0;
}

double belokurskaya::Concave::calculateTriangleArea(const point_t & p1, const point_t & p2, const point_t & p3) const
{
  return std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

void belokurskaya::Concave::getVertices(point_t & a, point_t & b, point_t & c, point_t & d) const
{
  a = a_;
  b = b_;
  c = c_;
  d = d_;
}

belokurskaya::point_t belokurskaya::Concave::calculateCentroid() const
{
  return d_;
}
