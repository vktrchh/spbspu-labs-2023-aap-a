#include "polygon.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "triangle.hpp"

grechishnikov::Polygon::Polygon(const grechishnikov::point_t* points, size_t size):
  points_(new grechishnikov::point_t[size]),
  size_(size)
{
  if (size < 3)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (Not enough arguments for Polygon)");
  }
  for (size_t i = 0; i < size; i++)
  {
    points_[i] = points[i];
  }
  try
  {
    for (size_t i = 2; i < size; i++)
    {
      Triangle triangle(points[0], points[i - 1], points[i]);
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
  double result = 0;
  for (size_t i = 2; i < size_; i++)
  {
    Triangle triangle(points_[0], points_[i - 1], points_[i]);
    result += triangle.getArea();
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
    max_x = std::max(max_x, points_[i].x);
    max_y = std::max(max_y, points_[i].y);
    min_x = std::min(min_x, points_[i].x);
    min_y = std::min(min_y, points_[i].y);
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
