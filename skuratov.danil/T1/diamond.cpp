#include "diamond.h"

#include <stdexcept>
#include <cmath>
#include <algorithm>

skuratov::Diamond::Diamond(const point_t& corner1, const point_t& corner2, const point_t& corner3):
  corner1_(corner1),
  corner2_(corner2),
  corner3_(corner3)
{
  if (!((corner1_.x == corner2_.x && corner2_.y == corner3_.y)
    || (corner1_.x == corner3_.x && corner1_.y == corner2_.y)
    || (corner1_.y == corner2_.y && corner2_.x == corner3_.x)))
  {
    throw std::invalid_argument("Error: diagonals of the diamond must be parallel to the coordinate axes");
  }
}

double skuratov::Diamond::getArea() const
{
  double diagonal1 = std::sqrt(std::pow(corner1_.x - corner3_.x, 2) + std::pow(corner1_.y - corner3_.y, 2));
  double diagonal2 = std::sqrt(std::pow(corner1_.x - corner2_.x, 2) + std::pow(corner1_.y - corner2_.y, 2));
  return (diagonal1 * diagonal2) / 2;
}

skuratov::rectangle_t skuratov::Diamond::getFrameRect() const
{
  double minX = std::min({ corner1_.x, corner2_.x, corner3_.x });
  double maxX = std::max({ corner1_.x, corner2_.x, corner3_.x });
  double minY = std::min({ corner1_.y, corner2_.y, corner3_.y });
  double maxY = std::max({ corner1_.y, corner2_.y, corner3_.y });

  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = { minX + width / 2, minY + height / 2 };
  return { width, height, pos };
}

void skuratov::Diamond::move(const point_t& A)
{
  rectangle_t B = getFrameRect();
  move(A.x - B.pos.x, A.y - B.pos.y);
}

void skuratov::Diamond::move(double dx, double dy)
{
  corner1_.x += dx;
  corner2_.x += dx;
  corner3_.x += dx;

  corner1_.y += dy;
  corner2_.y += dy;
  corner3_.y += dy;
}

void skuratov::Diamond::scale(double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Error: scale factor of diamond should be a positive");
  }

  rectangle_t B = getFrameRect();
  point_t center = B.pos;
  corner1_.x = center.x + scalingFactor * (corner1_.x - center.x);
  corner1_.y = center.y + scalingFactor * (corner1_.y - center.y);
  corner2_.x = center.x + scalingFactor * (corner2_.x - center.x);
  corner2_.y = center.y + scalingFactor * (corner2_.y - center.y);
  corner3_.x = center.x + scalingFactor * (corner3_.x - center.x);
  corner3_.y = center.y + scalingFactor * (corner3_.y - center.y);
}
