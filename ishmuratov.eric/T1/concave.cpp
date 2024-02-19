#include "concave.hpp"

ishmuratov::Concave::Concave(const point_t & point1, const point_t & point2, const point_t & point3, const point_t & point4):
  corner1_(point1),
  corner2_(point2),
  corner3_(point3),
  center_(point4)
{
  if (triangleArea(corner1_, corner2_, corner3_) == 0)
  {
    throw std::invalid_argument("First 3 points don't form triangle!");
  }
  ishmuratov::point_t v14 = { corner1_.x - center_.x, corner1_.y - center_.y };
  ishmuratov::point_t v21 = { corner2_.x - corner1_.x, corner2_.y - corner1_.y };
  ishmuratov::point_t v24 = { corner2_.x - center_.x, corner2_.y - center_.y };
  ishmuratov::point_t v32 = { corner3_.x - corner2_.x, corner3_.y - corner2_.y };
  ishmuratov::point_t v34 = { corner3_.x - center_.x, corner3_.y - center_.y };
  ishmuratov::point_t v13 = { corner1_.x - corner3_.x, corner1_.y - corner3_.y };
  double ps1 = ishmuratov::pseudoScalar(v14, v21);
  double ps2 = ishmuratov::pseudoScalar(v24, v32);
  double ps3 = ishmuratov::pseudoScalar(v34, v13);
  if (!(ps1 < 0 && ps2 < 0 && ps3 < 0) && !(ps1 > 0 && ps2 > 0 && ps3 > 0))
  {
    throw std::invalid_argument("Last point is outside of the triangle!");
  }
}

ishmuratov::Concave::~Concave() = default;

ishmuratov::Triangle * ishmuratov::Concave::triangleCut() const
{

}

double ishmuratov::Concave::getArea() const
{

}

ishmuratov::rectangle_t ishmuratov::Concave::getFrameRect() const
{

}

void ishmuratov::Concave::move(point_t & position)
{

}

void ishmuratov::Concave::move(double dx, double dy)
{

}

void ishmuratov::Concave::scale(double factor)
{

}
