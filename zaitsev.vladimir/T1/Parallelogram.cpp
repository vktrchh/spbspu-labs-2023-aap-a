#include "parallelogram.hpp"
#include <stdexcept>
#include <cstring>
#include <cmath>
#include <cstddef>
#include <limits>
#include <algorithm>
#include "base-types.hpp"
#include "Geom_functions.h"


zaitsev::Parallelogram::Parallelogram(const point_t* vertices)
{
  if (vertices[0].y != vertices[1].y && vertices[2].y != vertices[1].y)
  {
    throw std::invalid_argument("Sides are not parallel to x axis");
  }
  if (getAreaOfTriangle(vertices[0],vertices[1],vertices[2])==0)
  {
    throw std::invalid_argument("Parallelogram degenerated into a point");
  }
  if (vertices[0].y != vertices[1].y)
  {
    def_vertices_[0] = vertices[2];
    def_vertices_[1] = vertices[1];
    def_vertices_[2] = vertices[0];
  }
  else
  {
    std::memcpy(def_vertices_, vertices, 3 * sizeof(point_t));
  }
}

double zaitsev::Parallelogram::getArea() const
{
  return 2 * getAreaOfTriangle(def_vertices_[0], def_vertices_[1], def_vertices_[2]);
}

zaitsev::rectangle_t zaitsev::Parallelogram::getFrameRect() const
{
  point_t left_corner = def_vertices_[0] + def_vertices_[2] - def_vertices_[1];
  point_t right_corner = left_corner;

  for (size_t i = 0; i < 3; ++i)
  {
    changeRectangleBounds(left_corner, right_corner, def_vertices_[i]);
  }

  point_t size = right_corner - left_corner;
  point_t pos = (left_corner + right_corner) / 2;
  return { size.x, size.y, pos };
}

void zaitsev::Parallelogram::move(const point_t& dest_pos)
{
  point_t pos = getCenter();
  move(dest_pos.x - pos.x, dest_pos.y - pos.y);
}

void zaitsev::Parallelogram::move(double x_shift, double y_shift)
{
  point_t shift = { x_shift, y_shift };
  for (size_t i = 0; i < 3; ++i)
  {
    def_vertices_[i] += shift;
  }
}

void zaitsev::Parallelogram::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::invalid_argument("Scale factor must be positive");
  }
  point_t center = getCenter();
  for (size_t i = 0; i < 3; ++i)
  {
    def_vertices_[i] = center + (def_vertices_[i] - center) * factor;
  }
}

zaitsev::point_t zaitsev::Parallelogram::getCenter() const
{
  return (def_vertices_[0] + def_vertices_[2]) / 2;
}
