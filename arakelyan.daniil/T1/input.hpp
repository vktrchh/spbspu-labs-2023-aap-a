#ifndef INPUT_HPP
#define INPUT_HPP
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
namespace arakelyan
{
  arakelyan::Shape ** inputData(std::istream &input);
  void freeMem(Shape ** shapes, const char * string, const size_t countOfshapes);
}
#endif
