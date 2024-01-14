#include "polygon.hpp"
#include <stdexcept>
#include <iostream>

int main()
{
  using namespace grechishnikov;
  point_t a { 1.0, 1.0 }, b { 5.0, 1.0 }, d { 15.0, 9.0 }, c { 1.0, 5.0 };
  point_t points[] = { a, b, d, c };
  Polygon poly = { points, 4 };
  rectangle_t t = poly.getFrameRect();
  std::cout << t.width << " " << t.height << " " << t.pos.x << " " << t.pos.y << "\n";
  std::cout << poly.getArea() << "\n";
  std::cout << "\n";
  poly.scale(2.0);
  rectangle_t t2 = poly.getFrameRect();
  std::cout << t2.width << " " << t2.height << " " << t2.pos.x << " " << t2.pos.y << "\n";
  std::cout << poly.getArea() << "\n";

  {
    Polygon p = { points, 4 };
    rectangle_t fr = p.getFrameRect();
    std::cout << t.width << " " << t.height << "\n";
  }
  std::cout << "end\n";
}
