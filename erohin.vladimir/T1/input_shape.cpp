#include "input_shape.hpp"
#include <stdexcept>
#include <iostream>
#include "triangle.hpp"
#include "shape.hpp"
#include "input_string.hpp"
#include "parse.hpp"

void erohin::inputShape(Shape** result, std::istream& input, size_t& size, point_t& pos, double& ratio)
{
  Shape** temp = nullptr;
  char* str = nullptr;
  size_t i = 0;
  try
  {
    str = new char[20 + 1]{'0'};
    while (!input.eof())
    {
      if (!input)
      {
        throw std::logic_error("Wrong input");
      }
      str = inputString(input, str);
      Shape* shape_ptr = parseShape(str, pos, ratio);
      if (shape_ptr)
      {
        result[i++] = shape_ptr;
      }
    }
  }
  catch (...)
  {
    freeShape(result, size);
    delete[] str;
    throw;
  }
  size = i;
  delete[] str;
  if (ratio <= 0.0)
  {
    throw std::invalid_argument("Scale command do not find");
  }
}

void erohin::freeShape(Shape** shape, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shape[i];
  }
}
