#include <iostream>
#include <vector>
#include <memory>
#include <sstream>

#include "diamond.h"
#include "rectangle.h"
#include "square.h"

using namespace skuratov;

int main()
{
  const int numShapes = 1000;
  std::vector<std::unique_ptr<Shape>> shapes;
  shapes.reserve(numShapes);

  std::string input;
  for (int i = 0; i < numShapes; ++i)
  {
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::string type;
    iss >> type;
    if (type == "DIAMOND")
    {
      double x1, y1, x2, y2, x3, y3;
      iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      std::unique_ptr<Diamond> diamond(new Diamond(point_t{ x1, y1 }, point_t{ x2, y2 }, point_t{ x3, y3 }));
      shapes.push_back(std::move(diamond));
    }
    else if (type == "RECTANGLE")
    {
      double x, y, width, height;
      iss >> x >> y >> width >> height;
      std::unique_ptr<Rectangle> rectangle(new Rectangle(point_t{ x, y }, point_t{ x + width, y + height }));
      shapes.push_back(std::move(rectangle));
    }
    else if (type == "SQUARE")
    {
      double x, y, sideLength;
      iss >> x >> y >> sideLength;
      std::unique_ptr<Square> square(new Square(point_t{ x, y }, sideLength));
      shapes.push_back(std::move(square));
    }
  }
  for (const auto& shape: shapes)
  {
    std::cout << "Area: " << shape->getArea() << '\n';
    rectangle_t frameRect = shape->getFrameRect();
    std::cout << "Frame Rectangle: width =" << frameRect.width << ", height =" << frameRect.height << ", pos = ("
      << frameRect.pos.x << ", " << frameRect.pos.y << ")" << '\n';
  }
  return 0;
}
