#include "triangle.hpp"

ishmuratov::Triangle::Triangle(const point_t & point1, const point_t & point2, const point_t & point3):
  corners_{ point1, point2, point3 }
{
  if (triangleArea(corners_[0], corners_[1], corners_[2]) == 0)
  {
    throw std::invalid_argument("This is not a triangle!");
  }
}

ishmuratov::Triangle::~Triangle() = default;

double ishmuratov::Triangle::getArea()
{
  return triangleArea(corners_[0], corners_[1], corners_[2]);
}

ishmuratov::rectangle_t ishmuratov::Triangle::getFrameRect() const
{
  point_t botLeft = { std::min(corners_[0].x, std::min(corners_[1].x, corners_[2].x)), std::min(corners_[0].y, std::min(corners_[1].y, corners_[2].y)) };
  point_t topRight = { std::max(corners_[0].x, std::max(corners_[1].x, corners_[2].x)), std::max(corners_[0].y, std::max(corners_[1].y, corners_[2].y)) };
  double frame_width = topRight.x - botLeft.x;
  double frame_height = topRight.y - botLeft.y;
  point_t frame_pos = { botLeft.x + (frame_width / 2), botLeft.y + (frame_height / 2) };
  return { frame_width, frame_height, frame_pos };
}

void ishmuratov::Triangle::move(point_t & position)
{
  point_t center = triangleCenter(corners_[0], corners_[1], corners_[2]);
  double dx = position.x - center.x;
  double dy = position.y - center.y;
  move(dx, dy);
}

void ishmuratov::Triangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 3; ++i)
  {
    corners_[i] = { corners_[i].x + dx, corners_[i].y + dy };
  }
}

void ishmuratov::Triangle::scale(double factor)
{
  point_t center = triangleCenter(corners_[0], corners_[1], corners_[2]);
  scaleTriangle(corners_, center, factor);
}
