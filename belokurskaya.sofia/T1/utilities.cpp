#include "utilities.hpp"

Rectangle readRectangle()
{
  float x1, y1, x2, y2;
  std::cin >> x1 >> y1;
  std::cin >> x2 >> y2;

  float width = x2 - x1;
  float height = y2 - y1;

  float centerX = x1 + width / 2;
  float centerY = y1 + height / 2;

  return Rectangle({centerX, centerY}, width, height);
}

void printShapeInfo(const Shape & shape)
{
  std::cout << shape.getArea() << " ";
  rectangle_t frameRect = shape.getFrameRect();
  std::cout << frameRect.pos.x - frameRect.width / 2 << " "
            << frameRect.pos.y - frameRect.height / 2 << " "
            << frameRect.pos.x + frameRect.width / 2 << " "
            << frameRect.pos.y + frameRect.height / 2 << " ";
  std::cout << "\n";
}
