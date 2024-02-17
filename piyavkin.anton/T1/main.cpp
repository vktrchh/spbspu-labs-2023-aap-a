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
    CompositeShape cs(2);
    for (size_t i = 0; i < shapeCount; ++i)
    {
      cs.push_back(shapes[i]);
    }
    delete[] shapes;
    double k = 0;
    point_t center = {0, 0};
    std::cin >> center.x >> center.y >> k;
    std::cout << std::fixed;
    std::cout.precision(1);
    output(std::cout, cs);
    std::cout << '\n';
    for (size_t i = 0; i < cs.size(); ++i)
    {
      isoScale(&cs[i], center, k);
    }
    output(std::cout, cs);
    std::cout << '\n';
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
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
