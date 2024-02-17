#include "triangle.hpp"

ishmuratov::Triangle::Triangle(const point_t & point1, const point_t & point2, const point_t & point3):
  corner1_(point1),
  corner2_(point2),
  corner3_(point3)
{
  if (triangleArea(corner1_, corner2_, corner3_) == 0)
  {
    throw std::invalid_argument("This is not a triangle!");
  }
}

ishmuratov::Triangle::~Triangle() = default;

double ishmuratov::Triangle::getArea() const
{
  return triangleArea(corner1_, corner2_, corner3_);
}

ishmuratov::rectangle_t ishmuratov::Triangle::getFrameRect() const
{
  point_t botLeft = { std::min(corner1_.x, std::min(corner2_.x, corner3_.x)), std::min(corner1_.y, std::min(corner2_.y, corner3_.y)) };
  point_t topRight = { std::max(corner1_.x, std::max(corner2_.x, corner3_.x)), std::max(corner1_.y, std::max(corner2_.y, corner3_.y)) };
  double frame_width = topRight.x - botLeft.x;
  double frame_height = topRight.y - botLeft.y;
  point_t frame_pos = { botLeft.x + (frame_width / 2), botLeft.y + (frame_height / 2) };
  return { frame_width, frame_height, frame_pos };
}

void ishmuratov::Triangle::move(point_t & position)
{
  point_t center = triangleCenter(corner1_, corner2_, corner3_);
  double dx = position.x - center.x;
  double dy = position.y - center.y;
  move(dx, dy);
}

void ishmuratov::Triangle::move(double dx, double dy)
{
  corner1_ = { corner1_.x + dx, corner1_.y + dy };
  corner2_ = { corner2_.x + dx, corner2_.y + dy };
  corner3_ = { corner3_.x + dx, corner3_.y + dy };
}

void ishmuratov::Triangle::scale(double factor)
{
  point_t center = triangleCenter(corner1_, corner2_, corner3_);
  point_t pointArray[3] = {corner1_, corner2_, corner3_};
  point_t diffArray[3] = {};
  for (int i = 0; i < 3; ++i)
  {
    diffArray[i] = { (pointArray[i].x - center.x) * factor, (pointArray[i].y - center.y) * factor };
    pointArray[i] = { center.x + diffArray[i].x, center.y + diffArray[i].y };
  }
  corner1_ = pointArray[0];
  corner2_ = pointArray[1];
  corner3_ = pointArray[2];
}
