#include <iostream>
#include <iomanip>
#include "base-types.hpp"
#include "shape.hpp"
#include <cstring>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "Parallelogram.hpp"
#include "inputShapes.hpp"
#include "stringProc.hpp"

using namespace strelyaev;

void printCoords(Shape * shape)
{
  rectangle_t rect = shape->getFrameRect();
  double left_bottom_x = rect.pos_.x_ - rect.width_ / 2;
  double left_bottom_y = rect.pos_.y_ - rect.height_ / 2;
  double right_top_x = rect.pos_.x_ + rect.width_ / 2;
  double right_top_y = rect.pos_.y_ + rect.height_ / 2;
  std::cout << shape->getArea() << " " << left_bottom_x << " ";
  std::cout << left_bottom_y << " " << right_top_x << " " << right_top_y << "\n";
}

void scaleShapes(Shape ** list, size_t current_index, const double arguments[3], const size_t max_shapes)
{
  if (current_index == 0)
  {
    throw std::logic_error("Nothing to scale");
  }
  if (arguments[2] < 0)
  {
    throw std::logic_error("Invalid SCALE argument");
  }
  const point_t center = {arguments[0], arguments[1]};
  for (size_t i = 0; i < max_shapes; ++i)
  {
    if (list[i] == 0)
    {
      break;
    }
    printCoords(list[i]);
    isotrScale(list[i], center, arguments[2]);
    printCoords(list[i]);

  }
}

void printErrors(const char ** errors, size_t max_shapes)
{
  for (size_t i = 0; i < max_shapes; i++)
  {
    if (errors[i] == 0)
    {
      break;
    }
    std::cerr << errors[i] << "\n";
  }
}

int main ()
{
  const size_t max_shapes = 1000;
  char * string = nullptr;
  size_t current_index = 0;
  Shape ** list = new Shape * [max_shapes]{};
  const char ** errors = new const char * [max_shapes]{};
  size_t errors_count = 0;

  std::cin >> std::noskipws;
  while (true)
  {
    string = nullptr;
    try
    {
      string = inputString(std::cin);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      delete [] string;
      delete [] errors;
      for (size_t i = 0; i < current_index; i++)
      {
        delete list[i];
      }
      delete [] list;
      return 2;
    }
    if (strncmp("SCALE", string, 5) == 0)
    {
      size_t pos = 0;
      const char * argument_string = string + 6;
      double arguments[3]{};
      for (size_t i = 0; i < 3; ++i)
      {
        arguments[i] = std::stod(argument_string, std::addressof(pos));
        argument_string += pos;
      }
      try
      {
        scaleShapes(list, current_index, arguments, max_shapes);
        delete [] string;
        break;
      }
      catch(const std::exception & e)
      {
        std::cerr << e.what() << '\n';
        delete [] string;
        for (size_t i = 0; i < current_index; i++)
        {
          delete list[i];
        }
        delete [] list;
        delete [] errors;
        return 2;
      }
    }
    Shape * new_shape = nullptr;
    try
    {
      new_shape = getShape(string);
      if (new_shape != nullptr)
      {
        list[current_index++] = new_shape;
      }
    }
    catch(const std::invalid_argument & e)
    {
      errors[errors_count++] = e.what();
    }
    delete [] string;
  }
  std::cin >> std::skipws;

  printErrors(errors, max_shapes);
  delete [] list;
  delete [] errors;
}
