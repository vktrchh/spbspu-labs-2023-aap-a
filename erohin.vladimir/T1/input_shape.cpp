#include "input_shape.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include "triangle.hpp"
#include "shape.hpp"
#include "parse.hpp"

void erohin::inputShape(Shape** result, std::istream& input, size_t& size, point_t& pos, double& ratio)
{
  size = 0;
  bool isWrongFigureCreation = false;
  std::string str = "";
  try
  {
    char elem = 0;
    input >> std::noskipws;
    while (input >> elem)
    {
      if (elem == '\n')
      {
        try
        {
          Shape* shape_ptr = parseShape(str, pos, ratio);
          if (shape_ptr)
          {
            result[size++] = shape_ptr;
          }
        }
        catch (const std::invalid_argument&)
        {
          isWrongFigureCreation = true;
        }
        str = "";
      }
      else if (str.length() < str.max_size())
      {
        str += elem;
      }
      else
      {
        throw std::runtime_error("Line is too long");
      }
    }
    input >> std::skipws;
  }
  catch (...)
  {
    input >> std::skipws;
    throw;
  }
  if (ratio <= 0.0)
  {
    throw std::logic_error("Scale command do not find");
  }
  else if (isWrongFigureCreation)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
  else if (!result[0])
  {
    throw std::runtime_error("Nothing to scale");
  }
}

void erohin::freeShape(Shape** shape, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shape[i];
  }
}
