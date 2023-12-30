#include "inputShapes.hpp"
#include "shape.hpp"

baranov::Shape ** baranov::expandShapes(baranov::Shape ** shapes, const size_t size, const size_t newSize)
{
  baranov::Shape ** result = new baranov::Shape*[newSize];
  for (size_t i = 0; i < size; ++i)
  {
    result[i] = shapes[i];
  }
  return result;
}

