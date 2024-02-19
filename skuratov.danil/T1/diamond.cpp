#include "diamond.h"

#include <stdexcept>
#include <cmath>

skuratov::Diamond::Diamond(const point_t& corner1, const point_t& corner2, const point_t& corner3) :
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
{}

void skuratov::Diamond::move(const point_t& A)
{}

void skuratov::Diamond::move(double dx, double dy)
{}

void skuratov::Diamond::scale(double scalingFactor)
{
  if (scalingFactor <= 0)
  {
    throw std::invalid_argument("Error: scale factor of diamond should be a positive");
  }
}
