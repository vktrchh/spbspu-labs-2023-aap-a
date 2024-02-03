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
  size = 0;
  bool isWrongFigureCreation = false;
  try
  {
    str = new char[20 + 1]{'0'};
    Shape* shape_ptr = nullptr;
    while (!input.eof())
    {
      if (!input)
      {
        throw std::runtime_error("Wrong input");
      }
      str = inputString(input, str);
      try
      {
        shape_ptr = parseShape(str, pos, ratio);
      }
      catch (const std::invalid_argument&)
      {
        isWrongFigureCreation = true;
      }
      if (shape_ptr)
      {
        result[size++] = shape_ptr;
      }
    }
  }
  catch (...)
  {
    freeShape(result, size);
    delete[] str;
    throw;
  }
  delete[] str;
  if (ratio <= 0.0)
  {
    throw std::logic_error("Scale command do not find");
  }
  if (isWrongFigureCreation)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
}

void erohin::freeShape(Shape** shape, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shape[i];
  }
}
