#include "Complexquad.h"
#include <stdexcept>
#include <cstring>
#include <cmath>
#include <cstddef>
#include <limits>
#include <algorithm>
#include "base-types.h"
#include "Geom_functions.h"

zaitsev::Complexquad::Complexquad(const point_t* sections)
{
 if (!checkIntersection(sections))
 {
   throw std::invalid_argument("Lines are parallel");
 }
  std::memcpy(vertices, sections, sizeof(point_t));
}

double zaitsev::Complexquad::getArea() const
{
  point_t center = getCenter();
  return getAreaOfTriangle(center, vertices[0], vertices[3]) + getAreaOfTriangle(center, vertices[0], vertices[3]);
}

zaitsev::rectangle_t zaitsev::Complexquad::getFrameRect() const
{
  double low = std::numeric_limits< double >::max();
  double upper = std::numeric_limits< double >::min();
  double left = std::numeric_limits< double >::max();
  double right = std::numeric_limits< double >::min();
  
  for (size_t i = 0; i < 4; ++i)
  {
    low = std::min(low, vertices[i].y);
    upper = std::max(low, vertices[i].y);
    left = std::min(low, vertices[i].x);
    right = std::max(low, vertices[i].x);
  }

  double width = right - left;
  double height = upper - low;
  point_t pos = { (low + upper) / 2, (left + right) / 2 };
  return { width, height, pos };
}

void zaitsev::Complexquad::move(const point_t& dest_pos)
{
}

void zaitsev::Complexquad::move(double x_shift, double y_shift)
{
  for (size_t i = 0; i < 4; ++i)
  {
    vertices[i].x += x_shift;
    vertices[i].y += y_shift;
  }
}

zaitsev::point_t zaitsev::Complexquad::getCenter() const
{
  return findIntersection(vertices);
}

void zaitsev::Complexquad::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = getCenter();
  for (size_t i = 0; i < 4; ++i)
  {
    vertices[i].x = center.x + (vertices[i].x - center.x) * factor;
    vertices[i].y = center.y + (vertices[i].y - center.y) * factor;
  }
  return;
}
