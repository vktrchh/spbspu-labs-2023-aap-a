#ifndef INSERT_FIGURES_HPP
#define INSERT_FIGURES_HPP

#include <string>
#include "shape.hpp"

namespace nikitov
{
  Shape* insertRectangle(std::string line);

  Shape* insertDiamond(std::string line);

  Shape* insertRegular(std::string line);
}

#endif
