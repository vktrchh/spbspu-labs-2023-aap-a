#include <iostream>
#include <stdexcept>
#include "base-types.hpp"
#include "input.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

int main()
{
  point_t pointForIsoScale = {0.0, 0.0};
  double kForIsoScale = 0;
  using namespace arakelyan;
  Shape ** myShapes = nullptr;
  try
  {
    myShapes = inputData(std::cin, pointForIsoScale, kForIsoScale);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Bad allocation dynamic memory!\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  size_t size = 0;
  for (size_t i = 0; myShapes[i]; i++)
  {
    size++;
  }

  for (size_t i = 0; i < size; i++)
  {
    if (myShapes[i])
    {
      std::cout << myShapes[i]->getArea() << "\n";
    }
  }

  delete [] myShapes;
  return 0;
}
