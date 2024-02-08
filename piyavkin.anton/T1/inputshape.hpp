#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP
#include <istream>
#include "shape.hpp"
namespace piyavkin
{
  void clearMemory(Shape** shapes, size_t shapeCount);
  void inputRectangle(std::istream& in, Shape** shapes, size_t shapeCount);
  void inputTriangle(std::istream& in, Shape** shapes, size_t shapeCount);
  void inputParallelogram(std::istream& in, Shape** shapes, size_t shapeCount);
  Shape** inputShape(std::istream& in, size_t& shapeCount);
}
#endif
