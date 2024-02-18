#include "diamond.h"

#include <stdexcept>

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
{}

