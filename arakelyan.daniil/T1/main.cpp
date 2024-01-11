#include <iostream>
#include <iterator>
#include <stdexcept>
#include "input.hpp"
#include "base-types.hpp"
#include "parallelogram.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"


int main()
{
 point_t p1 = {10.0, 11.0};
 point_t p2 = {16.0, 8.0};
 point_t p3 = {10.0, 8.0};
 arakelyan::Diamond dia(p1,p2,p3);
 dia.getData();
 std::cout << "area in defolt par = " << dia.getArea() << "\n";
 rectangle_t dataOfFremeRect = dia.getFrameRect();
 std::cout << "frame rect: pos: x = " << dataOfFremeRect.pos_.x_ << ", y = " << dataOfFremeRect.pos_.y_ << "; width = " << dataOfFremeRect.width_ << "; height = " << dataOfFremeRect.height_ << "\n";
 std::cout << "scale 2\n";
 dia.scale(2.0);
 dia.getData();
 dataOfFremeRect = dia.getFrameRect();
 std::cout << "frame rect: pos: x = " << dataOfFremeRect.pos_.x_ << ", y = " << dataOfFremeRect.pos_.y_ << "; width = " << dataOfFremeRect.width_ << "; height = " << dataOfFremeRect.height_ << "\n";
}
