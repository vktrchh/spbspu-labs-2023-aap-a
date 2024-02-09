#include <iostream>
#include <iomanip>
#include <cstring>
#include <getString.hpp>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"
#include "inputShapes.hpp"
#include "stringProc.hpp"

using namespace strelyaev;

int main()
{
  std::cin >> std::noskipws;
  const size_t maxshapes = 1000;
  char * string = nullptr;
  size_t current_index = 0;
  Shape * list[maxshapes] = {nullptr};
  bool errors = false;
  bool scale_was_met = false;

  while (!scale_was_met)
  {
    if (!std::cin.good())
    {
      std::cerr << "Something went wrong with the input\n";
      for (size_t i = 0; i < current_index; i++)
      {
        delete list[i];
      }
      return 1;
    }

    try
    {
      string = getString(std::cin);
    }
    catch(const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      delete [] string;
      for (size_t i = 0; i < current_index; i++)
      {
        delete list[i];
      }
      return 2;
    }
    const char * shape_names[] = { "RECTANGLE", "TRIANGLE", "PARALLELOGRAM", "SCALE"};
    const size_t shapes_count = 4;
    try
    {
      for (size_t i = 0; i < shapes_count; i++)
      {
        size_t name_size = std::strlen(shape_names[i]);
        if (std::strncmp(shape_names[i], string, name_size) == 0)
        {
          if (i == 0)
          {
            list[current_index++] = inputRectangle(string);
          }
          if (i == 1)
          {
            list[current_index++] = inputTriangle(string);
          }
          if (i == 2)
          {
            list[current_index++] = inputParallelogram(string);
          }
          if (i == 3)
          {
            scale_was_met = true;
            scaleCommand(string, list, current_index, std::cout);
          }
        }
      }
    }
    catch(const std::exception& e)
    {
      errors = true;
    }
    delete [] string;
  }
  if (errors)
  {
    std::cerr << "Some shapes are incorrect!\n";
  }
  for (size_t i = 0; i < current_index; i++)
  {
    delete list[i];
  }
  std::cin >> std::skipws;
}
