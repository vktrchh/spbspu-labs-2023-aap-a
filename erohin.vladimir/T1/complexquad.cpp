#include "complexquad.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "geom_func.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

erohin::Complexquad::Complexquad() :
  vertex_(new point_t[4]{ {0.0, 0.0} }),
  center_({ 0.0, 0.0 })
{}

erohin::Complexquad::Complexquad(point_t* corner)
{
  vertex_ = new point_t[4]{ {0.0, 0.0} };
  for (int i = 0; i < 4; ++i)
  {
    vertex_[i] = corner[i];
  }
  try
  {
    center_ = findIntersectionPoint(vertex_);
    for (int i = 0; i < 3; i += 2)
    {
      if (!isPointOnSegment(center_, vertex_[i], vertex_[i + 1]))
      {
        throw std::invalid_argument("Complexquad vertexes are same points");
      }
    }
  }
  catch (const std::invalid_argument&)
  {
    delete[] vertex_;
    throw;
  }
}

erohin::Complexquad::~Complexquad()
{
  delete[] vertex_;
}

double erohin::Complexquad::getArea() const
{
  double area = 0.0;
  point_t point[3]{ {0.0, 0.0} };
  point[0] = center_;
  for (int i = 0; i < 2; ++i)
  {
    point[1] = vertex_[i];
    point[2] = vertex_[3 - i];
    area += Triangle(point).getArea();
  }
  return area;
}

erohin::rectangle_t erohin::Complexquad::getFrameRect() const
{
  return findPolygonFrameRect(vertex_, 4);
}

void erohin::Complexquad::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
  for (int i = 0; i < 4; ++i)
  {
    vertex_[i].x += dx;
    vertex_[i].y += dy;
  }
}

void erohin::Complexquad::move(point_t point)
{
  double dx = point.x - center_.x;
  double dy = point.y - center_.y;
  move(dx, dy);
}

void erohin::Complexquad::scale(double ratio)
{
  for (int i = 0; i < 4; ++i)
  {
    vertex_[i].x = center_.x + (vertex_[i].x - center_.x) * ratio;
    vertex_[i].y = center_.y + (vertex_[i].y - center_.y) * ratio;
  }
}
