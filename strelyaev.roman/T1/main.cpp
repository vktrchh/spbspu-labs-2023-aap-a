#include <iostream>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

Shape * makeTriangle()
{
  point_t p1 = {-1.0, 0};
  point_t p2 = {1.0, 0};
  point_t p3 = {0.0, 5.0};
  return new Triangle(p1, p2, p3);
}

int main ()
{
//  std::string shape_type = "";
//  std::cin >> shape_type;
  Shape * r1 = makeTriangle();
  std::cout << r1->getArea() <<"\n";
}
