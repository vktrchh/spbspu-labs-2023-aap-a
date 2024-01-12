#include "polygon.hpp"
#include "triangle.hpp"
#include <stdexcept>

grechishnikov::Polygon::Polygon(point_t* points, size_t size):
  points_(points),
  size_(size)
{
  if (size < 3)
  {
    throw std::invalid_argument("Invalid parameters (Not enough arguments for Polygon)");
  }
}

double grechishnikov::Polygon::getArea() const
{
  Triangle pTri[size_ - 2];
  for (size_t i = 2; i < size_; i++)
  {
    pTri[i - 2] = { points_[0], points_[i - 1], points_[i] };
  }

  return 0;
}

grechishnikov::rectangle_t grechishnikov::Polygon::getFrameRect() const
{
  double max_x = points_[0].x;
  double max_y = points_[0].y;
  double min_x = points_[0].x;
  double min_y = points_[0].y;

  for (size_t i = 1; i < size_; i++)
  {
    if (max_x < points_[i].x)
    {
      max_x = points_[i].x;
    }
  }

  for (size_t i = 1; i < size_; i++)
  {
    if (max_y < points_[i].y)
    {
      max_y = points_[i].y;
    }
  }

  for (size_t i = 1; i < size_; i++)
  {
    if (min_x > points_[i].x)
    {
      min_x = points_[i].x;
    }
  }

  for (size_t i = 1; i < size_; i++)
  {
    if (min_y > points_[i].y)
    {
      min_y = points_[i].y;
    }
  }

  double width = max_x - min_x;
  double height = max_y - min_y;
  point_t pos = { min_x + width / 2, min_y + height / 2 };
  return { width, height, pos };
}

void grechishnikov::Polygon::move(const point_t& pos)
{

}

void grechishnikov::Polygon::move(double dx, double dy)
{

}

void grechishnikov::Polygon::scale(double rate)
{

}

/*
Triangle* tiangulation(const Poligon& poly)
{
  Triangle** pTri = nullptr;
  try
  {
    pTri = new Triangle* [poly.size_ - 2] { nullptr };
    for (size_t i = 2; i < poly.size_; i++)
    {
      size_t iter = 0;
      Triangle tempTri(poly.points[0], poly.points[i - 1], poly.points[i];
      pTri[iter] = &tempTri;
    }
  }
}
*/
