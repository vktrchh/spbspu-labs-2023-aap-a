#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"

int main()
{
  using namespace ishmuratov;

  double x1 = 0;
  double y1 = 0;
  double x2 = 0;
  double y2 = 0;
  double x3 = 0;
  double y3 = 0;

  std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  point_t pointmove = { 10, 6 };
  Diamond di = Diamond({ x1, y1 }, { x2, y2 }, { x3, y3 });
  std::cout << di.getArea() << " " << di.getFrameRect().width << " " << di.getFrameRect().height << " " << di.getFrameRect().pos.x << " " << di.getFrameRect().pos.y << "\n";
  di.scale(2);
  std::cout << di.getArea() << " " << di.getFrameRect().width << " " << di.getFrameRect().height << " " << di.getFrameRect().pos.x << " " << di.getFrameRect().pos.y << "\n";
  di.move(pointmove);
  di.move(2, 4.55);
  std::cout << di.getArea() << " " << di.getFrameRect().width << " " << di.getFrameRect().height << " " << di.getFrameRect().pos.x << " " << di.getFrameRect().pos.y << "\n";
  return 0;
}
