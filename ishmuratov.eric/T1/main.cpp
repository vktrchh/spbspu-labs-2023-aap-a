#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"

int main()
{
  using namespace ishmuratov;
  double x1 = 0;
  double y1 = 0;
  double x2 = 0;
  double y2 = 0;
  double x3 = 0;
  double y3 = 0;
  double x4 = 0;
  double y4 = 0;
  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  Concave con = Concave({ x1, y1 }, { x2, y2 }, { x3, y3 }, { x4, y4 });
  return 0;
}
