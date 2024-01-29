#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP
#include <istream>
#include "shape.hpp"
namespace piyavkin
{
  size_t countIrregularFigures();
  Shape** inputShape(std::istream& in, size_t& shapeCount);
}
#endif
