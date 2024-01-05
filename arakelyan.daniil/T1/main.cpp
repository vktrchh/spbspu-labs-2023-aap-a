#include <iostream>
#include <stdexcept>
#include "input.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"


int main()
{
  point_t point1 = {7, 5};
  point_t point2 = {1, 1};
  try
  {
    Rectangle rec(point1, point2);

    std::cout << "7;5 - 1;1\n";
    rectangle_t data0 = rec.getFrameRect();
    std::cout << "area = " << rec.getArea() << "\n";
    std::cout << "get frame rect -> pos: x = " << data0.pos_.x_ << " y = " << data0.pos_.y_ << "; width = " << data0.width_ << "; height = " << data0.height_ << "\n";
    // rec.getData();

    std::cout << "scale = 2\n";
    rec.scale(2);
    rectangle_t data = rec.getFrameRect();
    std::cout << "area = " << rec.getArea() << "\n";
    std::cout << "get frame rect -> pos: x = " << data.pos_.x_ << " y = " << data.pos_.y_ << "; width = " << data.width_ << "; height_ = " << data.height_ << "\n";
    // rec.getData();

    std::cout << "move 2,4 \n";
    rec.move(2,4);
    rectangle_t data2 = rec.getFrameRect();
    std::cout << "get frame rect -> after move: pos: x = " << data2.pos_.x_ << " y = " << data2.pos_.y_ << "; width = " << data2.width_ << "; height_ = " << data2.height_ << "\n";
    // rec.getData();
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
 return 0;
}
