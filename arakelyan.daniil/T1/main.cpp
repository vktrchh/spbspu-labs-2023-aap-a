#include <iostream>
#include <stdexcept>
#include "input.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"


int main()
{
  point_t point1 = {6, 5};
  point_t point2 = {2, 3};
  try
  {
    Rectangle rec(point1, point2);

    std::cout << "6;5 - 2;3\n";
    rectangle_t data0 = rec.getFrameRect();
    std::cout << rec.getArea() << "\n";
    std::cout << "pos: x = " << data0.pos_.x_ << " y = " << data0.pos_.y_ << "; width = " << data0.width_ << "; height_ = " << data0.height_ << "\n";

    std::cout << "scale = 2\n";
    rec.scale(2);
    rectangle_t data = rec.getFrameRect();
    std::cout << rec.getArea() << "\n";
    std::cout << "pos: x = " << data.pos_.x_ << " y = " << data.pos_.y_ << "; width = " << data.width_ << "; height_ = " << data.height_ << "\n";

    std::cout << "move 2,4 \n";
    rec.move(2,4);
    rectangle_t data2 = rec.getFrameRect();
    std::cout << "after move: pos: x = " << data2.pos_.x_ << " y = " << data2.pos_.y_ << "; width = " << data2.width_ << "; height_ = " << data2.height_ << "\n";
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
 return 0;
}
