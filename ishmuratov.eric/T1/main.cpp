#include <iostream>
#include <stdexcept>
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "concave.hpp"
#include "data_process.hpp"
#include "input.hpp"
#include "output.hpp"

int main()
{
  using namespace ishmuratov;
  Shape * shapes[1000]{};
  point_t position = { 0, 0 };
  double factor = 0;
  bool invalidShape = false;
  size_t count = 0;
  try
  {
    inputShape(std::cin, shapes, count);
  }
  catch (const std::invalid_argument & e)
  {
    invalidShape = true;
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  outputShape(std::cout, shapes, count);
  std::cout << "\n";
  std::cin >> position.x >> position.y >> factor;
  if ((!std::cin) || (factor < 0))
  {
    throw std::out_of_range("Bad input!");
  }
  for (size_t i = 0; i < count; ++i)
  {
    scaleShapes(shapes[i], position, factor);
  }
  outputShape(std::cout, shapes, count);
  std::cout << "\n";
  if (invalidShape)
  {
    std::cerr << "Invalid shape!\n";
  }
  return 0;
}
