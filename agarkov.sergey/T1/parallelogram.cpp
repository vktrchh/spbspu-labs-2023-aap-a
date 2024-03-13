#include "parallelogram.hpp"
#include <stdexcept>

agarkov::Parallelogram::Parallelogram(point_t point1, point_t point2, point_t point3):
  point1_(point1), 
  point2_(point2), 
  point3_(point3)
{
}
