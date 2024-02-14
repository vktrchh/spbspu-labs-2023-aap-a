#include <iostream>
#include <string>
#include <cstddef>
#include "base-types.hpp"
#include "geometric_functions.hpp"
#include "shapes_i_o.hpp"
#include "composite_shape.hpp"

int main()
{
  using namespace zaitsev;
  std::string shape_type;
  CompositeShape shape;
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
          return 1;
        }

        if (shape_type == "RECTANGLE")
        {
          shape.push_back(readRectangle(std::cin));
        }
        else if (shape_type == "COMPLEXQUAD")
        {
          shape.push_back(readComplexquad(std::cin));
        }
        else if (shape_type == "PARALLELOGRAM")
        {
          shape.push_back(readParallelogram(std::cin));
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
    return 1;
  }

  double factor = 0;
  point_t center = { 0, 0 };
  try
  {
    readScale(std::cin, center, factor);
    std::cout << shape << "\n";
    scale(shape, factor, center);
    std::cout << shape << "\n";
    if (wrong_args)
    {
      std::cerr << "Warning: Some shapes were set incorrectly\n";
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error:" << e.what() << "\n";
    return 1;
  }

  return 0;
}