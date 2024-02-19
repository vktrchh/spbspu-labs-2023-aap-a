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
    {}
    else if (type == "RECTANGLE")
    {}
    else if (type == "SQUARE")
    {}
  }
  for (const auto& shape: shapes)
  {
    std::cout << "Area: " << shape->getArea() << std::endl;
    rectangle_t frameRect = shape->getFrameRect();
    std::cout << "Frame Rectangle: width =" << frameRect.width << ", height =" << frameRect.height << ", pos = ("
      << frameRect.pos.x << ", " << frameRect.pos.y << ")" << '\n';
  }
  return 0;
}
