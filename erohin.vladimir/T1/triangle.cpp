#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"
#include "geom_func.hpp"

erohin::Triangle::Triangle(point_t* corner)
{
  vertex_ = new point_t[3]{ {0.0, 0.0} };
  for (int i = 0; i < 3; ++i)
  {
    vertex_[i] = corner[i];
  }
  double* side = nullptr;
  try
  {
    side = getSides(vertex_, 3);
    for (int i = 0; i < 3; ++i)
    {
      if (side[i % 3] >= side[(i + 1) % 3] + side[(i + 2) % 3])
      {
        throw std::invalid_argument("Wrong figure creation");
      }
    }
  }
  catch (...)
  {
    delete[] vertex_;
    delete[] side;
    throw;
  }
  delete[] side;
}

erohin::Triangle::~Triangle()
{
  delete[] vertex_;
}

double erohin::Triangle::getArea() const
{
  double* side = getSides(vertex_, 3);
  double perimeter = 0.0;
  for (int i = 0; i < 3; ++i)
  {
    perimeter += side[i];
  }
  double result = perimeter / 2.0;
  for (int i = 0; i < 3; ++i)
  {
    result *= (perimeter / 2.0 - side[i]);
  }
  delete[] side;
  return std::sqrt(result);
}

erohin::rectangle_t erohin::Triangle::getFrameRect() const
{
  return findPolygonFrameRect(vertex_, 3);
}

void erohin::Triangle::move(double dx, double dy)
{
  for (int i = 0; i < 3; ++i)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}

erohin::point_t erohin::Triangle::getCenter() const
{
  point_t center = {0.0, 0.0};
  for (int i = 0; i < 3; ++i)
  {
    center.x += vertex_[i].x / 3.0;
    center.y += vertex_[i].y / 3.0;
  }
  return center;
}

void erohin::Triangle::move(point_t point)
{
  point_t center = getCenter();
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  move(dx, dy);
}

void erohin::Triangle::scale(double ratio)
{
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
  point_t center = getCenter();
  for (int i = 0; i < 3; ++i)
  {
    vertex_[i].x = center.x + (vertex_[i].x - center.x) * ratio;
    vertex_[i].y = center.y + (vertex_[i].y - center.y) * ratio;
  }
}
