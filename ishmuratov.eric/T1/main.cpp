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
  //std::cout << diamondCenter({ x1, y1 }, { x2, y2 }, { x3, y3 }).x << " " << diamondCenter({ x1, y1 }, { x2, y2 }, { x3, y3 }).y << "\n";
  //std::cout << diamondCenter({ x3, y3 }, { x2, y2 }, { x1, y1 }).x << " " << diamondCenter({ x3, y3 }, { x2, y2 }, { x1, y1 }).y << "\n";
  point_t pointmove = { 10, 6 };

  //Rectangle rect = Rectangle({ x1, y1 }, { x2, y2 });
  //std::cout << rect.getArea() << "\n";
  //rectangle_t new_rect = rect.getFrameRect();
  //std::cout << new_rect.width << " " << new_rect.height << " " << new_rect.pos.x << " " << new_rect.pos.y << "\n";

  //rect.move(pointmove);
  //rectangle_t new_rect1 = rect.getFrameRect();
  //std::cout << new_rect1.width << " " << new_rect1.height << " " << new_rect1.pos.x << " " << new_rect1.pos.y << "\n";

  //rect.scale(16);
  //std::cout << rect.getArea() << "\n";
  //rectangle_t new_rect2 = rect.getFrameRect();
  //std::cout << new_rect2.width << " " << new_rect2.height << " " << new_rect2.pos.x << " " << new_rect2.pos.y << "\n";

  //Triangle tri = Triangle({ x1, y1 }, { x2, y2 }, { x3, y3 });

  //std::cout << tri.getArea() << " " << tri.getFrameRect().width << " " << tri.getFrameRect().height << "\n";
  //std::cout << tri.getArea() << " " << tri.getFrameRect().width << " " << tri.getFrameRect().height << "\n";
  //tri.scale(2);
  //std::cout << tri.getFrameRect().width << " " << tri.getFrameRect().height << "\n";
  //std::cout << tri.getFrameRect().pos.x << "\n";
  //std:: cout << tri.getFrameRect().pos.y << "\n";
  //std::cout << tri.getFrameRect().width << "\n";
  //std::cout << tri.getFrameRect().height << "\n";

  Diamond di = Diamond({ x1, y1 }, { x2, y2 }, { x3, y3 });
  std::cout << di.getArea() << " " << di.getFrameRect().width << " " << di.getFrameRect().height << " " << di.getFrameRect().pos.x << " " << di.getFrameRect().pos.y << "\n";
  di.scale(2);
  std::cout << di.getArea() << " " << di.getFrameRect().width << " " << di.getFrameRect().height << " " << di.getFrameRect().pos.x << " " << di.getFrameRect().pos.y << "\n";
  di.move(pointmove);
  di.move(2, 4.55);
  std::cout << di.getArea() << " " << di.getFrameRect().width << " " << di.getFrameRect().height << " " << di.getFrameRect().pos.x << " " << di.getFrameRect().pos.y << "\n";
  return 0;
}
