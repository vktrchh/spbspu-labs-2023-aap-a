#include "polygon.hpp"
#include "triangle.hpp"
#include <stdexcept>
#include <iostream>

grechishnikov::Polygon::Polygon(const grechishnikov::point_t* points, size_t size):
  points_(nullptr),
  size_(size)
{
  if (size < 3)
  {
    throw std::invalid_argument("Invalid parameters (Not enough arguments for Polygon)");
  }

  points_ = new grechishnikov::point_t [size_];
  for (size_t i = 0; i < size_; i++)
  {
    points_[i] = points[i];
  }
  try
  {
    Triangle pTri[size_ - 2];
    for (size_t i = 2; i < size_; i++)
    {
      pTri[i - 2] = { points_[0], points_[i - 1], points_[i] };
    }
  }
  catch (const std::logic_error& e)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (some points are in a line)");
  }
}

grechishnikov::Polygon::~Polygon()
{
  delete[] points_;
}

double grechishnikov::Polygon::getArea() const
{
  Triangle pTri[size_ - 2];
  for (size_t i = 2; i < size_; i++)
  {
    pTri[i - 2] = { points_[0], points_[i - 1], points_[i] };
  }

  double result = 0;
  for (size_t i = 0; i < size_ - 2; i++)
  {
    result += pTri[i].getArea();
  }
  return result;
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
    if (max_y < points_[i].y)
    {
      max_y = points_[i].y;
    }
    if (min_x > points_[i].x)
    {
      min_x = points_[i].x;
    }
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
  double average_x = 0;
  double average_y = 0;
  for (size_t i = 0; i < size_; i++)
  {
    average_x += points_[i].x;
    average_y += points_[i].y;
  }
  average_x /= size_;
  average_y /= size_;
  point_t aPos = { average_x, average_y };
  move(pos.x - aPos.x, pos.y - aPos.y);
}

void grechishnikov::Polygon::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    points_[i].x += dx;
    points_[i].y += dy;
  }
}

void grechishnikov::Polygon::scale(double rate)
{
  double average_x = 0;
  double average_y = 0;
  for (size_t i = 0; i < size_; i++)
  {
    average_x += points_[i].x;
    average_y += points_[i].y;
  }
  average_x /= size_;
  average_y /= size_;
  point_t aPos = { average_x, average_y };

  for (size_t i = 0; i < size_; i++)
  {
    points_[i].x = aPos.x + (points_[i].x - aPos.x) * rate;
    points_[i].y = aPos.y + (points_[i].y - aPos.y) * rate;
  }
}
