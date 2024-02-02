#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP
#include <istream>
#include "shape.hpp"
namespace piyavkin
{
//  size_t countIrregularFigures();
  void clearMemory(Shape** shapes, size_t shapeCount);
  Shape** inputShape(std::istream& in, size_t& shapeCount);
}
#endif
