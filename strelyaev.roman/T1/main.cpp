#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
int main ()
{
  point_t p1 = {0.0, 0.0};
  point_t p2 = {1.0, 1.0};
  Rectangle r1 = {p1, p2};
  std::cout << r1.getArea() <<"\n";
}
