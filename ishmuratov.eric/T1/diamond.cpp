#include "diamond.hpp"

ishmuratov::Diamond::Diamond(const point_t & point1, const point_t & point2, const point_t & point3):
  corner1_(point1),
  corner2_(point2),
  corner3_(point3)
{
  if (triangleArea(corner1_, corner2_, corner3_) == 0)
  {
    throw std::invalid_argument("This is not a triangle!");
  }

  if (((corner1_.x != corner2_.x) && (corner1_.x != corner3_.x) \
                              && (corner2_.x != corner3_.x)) || \
     ((corner1_.y != corner2_.y) \
     && (corner1_.y != corner3_.y) && (corner2_.y != corner3_.y)))
  {
    throw std::invalid_argument("Diagonals of diamond must be parallel to axis!");
  }
}

ishmuratov::Diamond::~Diamond() = default;

double ishmuratov::Diamond::getArea() const
{
  Triangle tri = { corner1_, corner2_, corner3_ };
  return tri.getArea() * 4;
}

ishmuratov::rectangle_t ishmuratov::Diamond::getFrameRect() const
{
  Triangle tri = { corner1_, corner2_, corner3_ };
  rectangle_t frameRect = tri.Triangle::getFrameRect();
  frameRect.width *= 2;
  frameRect.height *= 2;
  frameRect.pos = diamondCenter(corner1_, corner2_, corner3_);
  return frameRect;
}

void ishmuratov::Diamond::move(point_t & position)
{
  point_t center = diamondCenter(corner1_, corner2_, corner3_);
  double dx = position.x - center.x;
  double dy = position.y - center.y;
  move(dx, dy);
}

void ishmuratov::Diamond::move(double dx, double dy)
{
  corner1_ = { corner1_.x + dx, corner1_.y + dy };
  corner2_ = { corner2_.x + dx, corner2_.y + dy };
  corner3_ = { corner3_.x + dx, corner3_.y + dy };
}

void ishmuratov::Diamond::scale(double factor)
{
  point_t center = diamondCenter(corner1_, corner2_, corner3_);
  point_t pointArray[3] = {corner1_, corner2_, corner3_};
  point_t diffArray[3] = {};
  for (int i = 0; i < 3; ++i)
  {
    diffArray[i] = { (pointArray[i].x - center.x) * factor, \
                     (pointArray[i].y - center.y) * factor };
    pointArray[i] = { center.x + diffArray[i].x, center.y + diffArray[i].y };
  }
  corner1_ = pointArray[0];
  corner2_ = pointArray[1];
  corner3_ = pointArray[2];
}



