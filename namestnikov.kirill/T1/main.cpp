#include <iostream>
#include "circle.hpp"
#include "complexquad.hpp"
#include "rectangle.hpp"
#include "input_output_shapes.hpp"
#include "geometric_functions.hpp"

int main()
{
  using namespace namestnikov;
  Shape ** shapes = nullptr;
  size_t count = 0;
  try
  {
    shapes = inputShapes(std::cin, count);
    outputShapes(std::cout, shapes, count);
    point_t scalePoint;
    double scaleCoefficient = 0.0;
    std::cin >> scalePoint.x >> scalePoint.y >> scaleCoefficient;
    if (!std::cin)
    {
      throw std::invalid_argument("Error in input\n");
      return 1;
    }
    if (scaleCoefficient < 0)
    {
      throw std::invalid_argument("Scaling coefficient must be greater than zero\n");
    }
    for (size_t i = 0; i < count; ++i)
    {
      isoScale(shapes[i], scalePoint, scaleCoefficient);
    }
    outputShapes(std::cout, shapes, count);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    deleteShapes(shapes, count);
    return 1;
  }
  deleteShapes(shapes, count);
}
