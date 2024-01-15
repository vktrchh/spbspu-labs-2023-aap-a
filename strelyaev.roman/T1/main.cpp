#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "Parallelogram.hpp"
#include "inputShapes.hpp"

char * inputString(std::istream & in)
{
  size_t size = 10;
  char * string = new char [size];
  char c = 0;
  size_t i = 0;
  while ((in >> c) && (c != '\n'))
  {
    if (!in)
    {
      delete [] string;
      throw std::logic_error("There is no input");
    }
    string[i++] = c;
    if (i == (size - 1))
    {
      size_t buffer_size = size + 10;
      char * buffer = nullptr;
      try
      {
        buffer = new char [buffer_size];
      }
      catch (...)
      {
        delete [] string;
        string = nullptr;
      }
      if (string == nullptr)
      {
        throw std::logic_error("Unable to create buffer");
      }
      for (size_t j = 0; j < i; j++)
      {
        buffer[j] = string[j];
      }
      delete [] string;
      string = buffer;
      size = buffer_size;
    }
  }
  string[i] = '\0';
  if ((string[0] == '\n') || (string[0] == '\0'))
  {
    delete [] string;
    throw std::logic_error("Unable to create string");
  }
  return string;
}

Shape * getShape(const char string[])
{
  const char * shape_names[] = { "RECTANGLE", "TRIANGLE", "PARALLELOGRAM"};
  const size_t shapes_count = 3;

  for (size_t i = 0; i < shapes_count; i++)
  {
    size_t name_size = strlen(shape_names[i]);
    if (strncmp(shape_names[i], string, name_size) == 0)
    {
      if (i == 0)
      {
        return inputRectangle(string);
      }
      if (i == 1)
      {
        return inputTriangle(string);
      }
      if (i == 2)
      {
        return inputParallelogram(string);
      }
    }
  }
  return nullptr;
}

void isotrScale(Shape * shape, const point_t point, const double k)
{
  point_t start_pos = shape->getFrameRect().pos_;
  shape->move(point);
  shape->scale(k);
  double x = (point.x_ - start_pos.x_) * k;
  double y = (point.y_ - start_pos.y_) * k;
  shape->move(-x, -y);
}

Shape ** makeList(Shape * new_shape, Shape ** old_list, size_t old_size)
{
  Shape ** new_list = new Shape * [old_size + 1];
  for (size_t i = 0; i < old_size; i++)
  {
    new_list[i] = old_list[i];
  }
  new_list[old_size] = new_shape;
  delete [] old_list;
  return new_list;
}

Shape ** extendErrors(const char ** errors, size_t error_count)
{
}

int main ()
{
  bool marker = true;
  size_t list_size = 1;
  Shape ** list = new Shape * [list_size];
  const char * errors[1] = {};
  size_t error_count = 0;


  std::cin >> std::noskipws;
  while (marker)
  {
    char * string = inputString(std::cin);
    if (strncmp("SCALE", string, 5) == 0)
    {
      double arguments[3]{};
      size_t pos = 0;
      const char * argument_string = string + 6;
      for (size_t i = 0; i < 3; ++i)
      {
        arguments[i] = std::stod(argument_string, std::addressof(pos));
        argument_string += pos;
      }
      const point_t center = {arguments[0], arguments[1]};

      for (size_t i = 1; i < list_size; i++)
      {
        std::cout << list[i]->getArea() << "\n";
        isotrScale(list[i], center, arguments[2]);
        std::cout << list[i]->getArea() << "\n";
      }
      return 0;
    }

    Shape * new_shape = nullptr;
    try
    {
      new_shape = getShape(string);
    }
    catch(const std::exception & e)
    {
      errors[error_count++] = e.what();
      continue;
    }
    list = makeList(new_shape, list, list_size);
    list_size += 1;
  }
  std::cin >> std::skipws;

}
