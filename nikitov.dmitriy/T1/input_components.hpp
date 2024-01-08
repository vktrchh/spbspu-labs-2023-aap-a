#ifndef INPUT_COMPONENTS_HPP
#define INPUT_COMPONENTS_HPP

#include <string>
#include "shape.hpp"

namespace nikitov
{
  Shape* recognizeFigure(std::string line);

  Shape** increaseArray(Shape** figures, size_t nFigures);
}

#endif
