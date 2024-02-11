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
