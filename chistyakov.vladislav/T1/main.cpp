#include <iostream>
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "shape.hpp"
#include "inputShapes.hpp"
#include "isotropScale.hpp"

int main()
{
  using namespace chistyakov;
  double scaleInfo[3]{};
  Shape * shapes[1000]{};

  for (size_t i = 0; i < 1000; ++i)
  {
    shapes[i] = nullptr;
  }

  try
  {
    inputShapes(std::cin, shapes, scaleInfo);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Achtung " << e.what() << "\n";
    freeArray(shapes, 1000);
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cout << "Error: " << e.what() << "\n";
    freeArray(shapes, 1000);
    return 2;
  }

  for (size_t i = 0; i < 1000; ++i)
  {
    if (shapes[i] == nullptr)
    {
      break;
    }
    std::cout << shapes[i]->getArea() << " ";
    shapes[i]->printCords();
    isotropScale(shapes[i], {scaleInfo[0], scaleInfo[1]}, scaleInfo[2]);
    std::cout << shapes[i]->getArea() << " ";
    shapes[i]->printCords();
  }

  freeArray(shapes, 1000);

  return 0;
};
