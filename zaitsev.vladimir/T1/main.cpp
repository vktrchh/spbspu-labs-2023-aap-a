#include <iostream>
#include <string>
#include <cstddef>
#include "base-types.hpp"
#include "geometric_functions.hpp"
#include "shapes_i_o.hpp"

int main()
{
  using namespace zaitsev;

  std::string shape_type;
  size_t size = 0;
  Shape* shapes[10'000] = {};
  bool wrong_args = false;

  try
  {
    std::cin >> shape_type;
    while (shape_type != "SCALE")
    {
      try
      {
        if (!std::cin)
        {
          std::cerr << "No scale command entered\n";
          freeShapes(shapes, size);
          return 1;
        }

        if (shape_type == "RECTANGLE")
        {
          shapes[size] = readRectangle(std::cin);
          ++size;
        }
        else if (shape_type == "COMPLEXQUAD")
        {
          shapes[size] = readComplexquad(std::cin);
          ++size;
        }
        else if (shape_type == "PARALLELOGRAM")
        {
          shapes[size] = readParallelogram(std::cin);
          ++size;
        }
        else
        {
          std::getline(std::cin, shape_type);
        }
      }
      catch (const std::invalid_argument&)
      {
        wrong_args = true;
      }
      std::cin >> shape_type;
    }
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Error: Failed to allocate memory\n";
    freeShapes(shapes, size);
    return 1;
  }

  if (size == 0)
  {
    std::cerr << "Error: No shapes to scale\n";
    return 1;
  }

  double factor = 0;
  point_t center = { 0, 0 };
  try
  {
    readScale(std::cin, center, factor);
    shapesOutput(std::cout, shapes, size) << "\n";
    for (size_t i = 0; i < size; ++i)
    {
      scale(shapes[i], factor, center);
    }
    shapesOutput(std::cout, shapes, size) << "\n";
    if (wrong_args)
    {
      std::cerr << "Warning: Some shapes were set incorrectly\n";
    }
  }
  catch (std::invalid_argument& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    freeShapes(shapes, size);
    return 1;
  }

  freeShapes(shapes, size);
  return 0;
}
