#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "isoscale.hpp"
#include "parallelogram.hpp"
#include "inputshape.hpp"
#include "output.hpp"
#include "compositeshape.hpp"

int main()
{
  piyavkin::Shape** shapes = nullptr;
  size_t shapeCount = 0;
  try
  {
    using namespace piyavkin;
    shapes = inputShape(std::cin, shapeCount);
    CompositeShape cs(100);
    std::cout << cs.empty() << '\n';
    for (size_t i = 0; i < shapeCount; ++i)
    {
      cs.push_back(shapes[i]);
    }
    std::cout << cs.empty() << ' ' << cs.size() << '\n';
    for (size_t i = 0; i < cs.size(); ++i)
    {
      std::cout << cs[i].getFrameRect().pos.x << ' ' << cs[i].getFrameRect().pos.y << '\n';
    }
    std::cout << cs.getArea() << '\n';
//    double k = 0;
//    point_t center = {0, 0};
//    std::cin >> center.x >> center.y >> k;
//    std::cout << std::fixed;
//    std::cout.precision(1);
//    output(std::cout, shapes, shapeCount);
//    std::cout << '\n';
//    for (size_t i = 0; i < shapeCount; ++i)
//    {
//      isoScale(shapes[i], center, k);
//    }
//    output(std::cout, shapes, shapeCount);
//    std::cout << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    if (shapes)
    {
      clearMemory(shapes, shapeCount);
    }
    return 1;
  }
}
