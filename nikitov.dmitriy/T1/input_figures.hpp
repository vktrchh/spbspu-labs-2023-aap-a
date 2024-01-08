#ifndef INPUT_FIGURES_HPP
#define INPUT_FIGURES_HPP

#include <ostream>
#include <string>
#include "shape.hpp"

namespace nikitov
{
  Shape** inputFigures(std::string& line, size_t& nFigures, std::istream& input);
}
#endif
