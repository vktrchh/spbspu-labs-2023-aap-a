#include "shape.hpp"

#include <stdexcept>

belokurskaya::Concave::Concave(const point_t & vertex1, const point_t & vertex2, const point_t & vertex3, const point_t & vertex4):
vertex1_(vertex1), vertex2_(vertex2), vertex3_(vertex3), vertex4_(vertex4)
{
  if (isTriangle(vertex1_, vertex2_, vertex3_))
  {
    if (!isInsideTriangle(vertex1_, vertex2_, vertex3_, vertex4_))
    {
      throw std::invalid_argument("Fourth vertex must be inside the triangle formed by the first three vertices");
    }
    if (isConcave(vertex1_, vertex2_, vertex3_, vertex4_))
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
  double triangle1_area = calculateTriangleArea(vertex1_, vertex2_, vertex4_);
  double triangle2_area = calculateTriangleArea(vertex2_, vertex3_, vertex4_);
  return triangle1_area + triangle2_area;
}

belokurskaya::rectangle_t belokurskaya::Concave::getFrameRect() const
{
  double min_x = std::min(std::min(std::min(vertex1_.x, vertex2_.x), vertex3_.x), vertex4_.x);
  double min_y = std::min(std::min(std::min(vertex1_.y, vertex2_.y), vertex3_.y), vertex4_.y);
  double max_x = std::max(std::max(std::max(vertex1_.x, vertex2_.x), vertex3_.x), vertex4_.x);
  double max_y = std::max(std::max(std::max(vertex1_.y, vertex2_.y), vertex3_.y), vertex4_.y);
  point_t center = {(min_x + max_x) / 2, (min_y + max_y) / 2};
  return {center, max_x - min_x, max_y - min_y};
}

void belokurskaya::Concave::move(const point_t & new_pos)
{
  double dx = new_pos.x - getFrameRect().pos.x;
  double dy = new_pos.y - getFrameRect().pos.y;
  vertex1_.x += dx;
  vertex1_.y += dy;
  vertex2_.x += dx;
  vertex2_.y += dy;
  vertex3_.x += dx;
  vertex3_.y += dy;
  vertex4_.x += dx;
  vertex4_.y += dy;
}

void belokurskaya::Concave::move(double dx, double dy)
{
  vertex1_.x += dx;
  vertex1_.y += dy;
  vertex2_.x += dx;
  vertex2_.y += dy;
  vertex3_.x += dx;
  vertex3_.y += dy;
  vertex4_.x += dx;
  vertex4_.y += dy;
}

double belokurskaya::Concave::calculateTriangleArea(const point_t & p1, const point_t & p2, const point_t & p3) const
{
  return std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}
