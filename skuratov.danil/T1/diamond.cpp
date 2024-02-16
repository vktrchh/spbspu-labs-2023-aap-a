#include "diamond.h"

#include <stdexcept>

skuratov::Diamond::Diamond(const point_t& corner1, const point_t& corner2, const point_t& corner3):
  corner1_(corner1),
  corner2_(corner2),
  corner3_(corner3)
{}
