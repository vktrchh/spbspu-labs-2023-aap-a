#include <iostream>
#include <stdexcept>
#include "input.hpp"
#include "base-types.hpp"
#include "parallelogram.hpp"
#include "shape.hpp"
#include "rectangle.hpp"


int main()
{
   point_t point1 = {2, 3};
   point_t point2 = {7, 3};
   point_t point3 = {10, 6};
   point_t pointToMove = {2, 4};
  // Rectangle rec(point1, point2);
  Parallelogram par(point1, point2, point3);
  par.getData();
  std::cout << "area = " << par.getArea() << "\n";
  std::cout << "frameRect:\n";
  rectangle_t dataFrame = par.getFrameRect();
  std::cout << "data: высота = " << dataFrame.height_ << "; шир = " << dataFrame.width_ << "; pos: x = " << dataFrame.pos_.x_ << "; y = " << dataFrame.pos_.y_ << "\n";
  // std::cout << "move(point{9,9})\n";
  // par.move(pointToMove);
  // par.getData();
  std::cout << "scale 2\n";
  par.scale(2);
  par.getData();

 return 0;
}
