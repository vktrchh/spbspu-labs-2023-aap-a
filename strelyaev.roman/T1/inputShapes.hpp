#ifndef INPUT_SHAPES_HPP
#define INPUT_SHAPES_HPP
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "Parallelogram.hpp"
namespace strelyaev
{
  Shape * inputRectangle(const char string[]);
  Shape * inputTriangle(const char string[]);
  Shape * inputParallelogram(const char string[]);
}
#endif
