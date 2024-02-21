#include "concave.hpp"

ishmuratov::Concave::Concave(const point_t & point1, const point_t & point2, const point_t & point3, const point_t & point4):
  corners_{ point1, point2, point3 },
  center_(point4)
{
  if (triangleArea(corners_[0], corners_[1], corners_[2]) == 0)
  {
    throw std::invalid_argument("First 3 points don't form triangle!");
  }
  ishmuratov::point_t v14 = { corners_[0].x - center_.x, corners_[0].y - center_.y };
  ishmuratov::point_t v21 = { corners_[1].x - corners_[0].x, corners_[1].y - corners_[0].y };
  ishmuratov::point_t v24 = { corners_[1].x - center_.x, corners_[1].y - center_.y };
  ishmuratov::point_t v32 = { corners_[2].x - corners_[1].x, corners_[2].y - corners_[1].y };
  ishmuratov::point_t v34 = { corners_[2].x - center_.x, corners_[2].y - center_.y };
  ishmuratov::point_t v13 = { corners_[0].x - corners_[2].x, corners_[0].y - corners_[2].y };
  double ps1 = ishmuratov::pseudoScalar(v14, v21);
  double ps2 = ishmuratov::pseudoScalar(v24, v32);
  double ps3 = ishmuratov::pseudoScalar(v34, v13);
  if (!(ps1 < 0 && ps2 < 0 && ps3 < 0) && !(ps1 > 0 && ps2 > 0 && ps3 > 0))
  {
    throw std::invalid_argument("Last point is outside of the triangle!");
  }
}

ishmuratov::Concave::~Concave() = default;

double ishmuratov::Concave::triangleCut() const
{
  Triangle array[2] = { { { 0, 0 }, { 0, 1 }, { 1, 0 } }, { { 0, 0 }, { 0, 1 }, { 1, 0 } } };
  array[0] = { corners_[0], corners_[1], corners_[2] };
  array[1] = { corners_[1], corners_[2], center_ };
  return array[0].getArea() - array[1].getArea();
}

double ishmuratov::Concave::getArea() const
{
  return triangleCut();
}

ishmuratov::rectangle_t ishmuratov::Concave::getFrameRect() const
{
  Triangle tri = { corners_[0], corners_[1], corners_[2] };
  return tri.getFrameRect();
}

void ishmuratov::Concave::move(point_t & position)
{
  double dx = position.x - center_.x;
  double dy = position.y - center_.y;
  move(dx, dy);
}

void ishmuratov::Concave::move(double dx, double dy)
{
  for (size_t i = 0; i < 3; ++i)
  {
    corners_[i] = { corners_[i].x + dx, corners_[i].y + dy};
  }
  center_ = { center_.x + dx, center_.y + dy };
}

void ishmuratov::Concave::scale(double factor)
{
  scaleTriangle(corners_, center_, factor);
}
