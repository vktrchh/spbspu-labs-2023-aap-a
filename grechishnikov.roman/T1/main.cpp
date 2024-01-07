#include "triangle.hpp"
#include <stdexcept>
#include <iostream>

int main()
{
  using namespace grechishnikov;
  point_t a { 1.0, 1.0 }, b { 5.0, 5.0 }, c { 5.0, 1.0 };
  Triangle tr(a, b, c);
  rectangle_t t = tr.getFrameRect();
  std::cout << t.width << " " << t.height << " " << t.pos.x << " " << t.pos.y << "\n";
  std::cout << tr.getArea() << "\n";
  std::cout << "\n";
  tr.scale(2.0);
  rectangle_t t2 = tr.getFrameRect();
  std::cout << t2.width << " " << t2.height << " " << t2.pos.x << " " << t2.pos.y << "\n";
  std::cout << tr.getArea() << "\n";
}
