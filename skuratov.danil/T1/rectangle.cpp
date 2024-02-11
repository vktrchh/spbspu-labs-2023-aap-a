#include "rectangle.h"
#include <stdexcept>

Skuratov::Rectangle::Rectangle(const point_t &lowerLeftCorner, const point_t &upperRightCorner):
  lowerLeftCorner_(lowerLeftCorner),
  upperRightCorner_(upperRightCorner)
{}
