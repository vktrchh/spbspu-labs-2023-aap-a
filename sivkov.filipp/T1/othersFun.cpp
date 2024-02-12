#include "base-types.hpp"
#include "shape.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>

void outputFrameRectInfo(std::ostream& out, const Shape* shape)
{
  out << " ";
  out << shape->getFrameRect().pos.x - shape->getFrameRect().width / 2 << " ";
  out << shape->getFrameRect().pos.y - shape->getFrameRect().height / 2 << " ";
  out << shape->getFrameRect().pos.x + shape->getFrameRect().width / 2 << " ";
  out << shape->getFrameRect().pos.y + shape->getFrameRect().height / 2 << "\n";
}
