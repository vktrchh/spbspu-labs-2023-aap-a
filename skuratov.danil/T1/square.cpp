#include "square.h"

#include <stdexcept>

skuratov::Square::Square(const point_t& bottomLeftCorner, double sideLength):
  bottomLeftCorner_(bottomLeftCorner),
  sideLength_(sideLength)
{}