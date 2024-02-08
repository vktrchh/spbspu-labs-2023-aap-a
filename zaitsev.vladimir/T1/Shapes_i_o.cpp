#include "Shapes_i_o.h"
#include <string>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <cstddef>
#include <istream>
#include <string>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include "parallelogram.hpp"
#include "Geom_functions.h"

double zaitsev::readNextValue(std::istream& input)
{
  std::string s;
  input >> s;
  return stod(s);
}

zaitsev::Shape* zaitsev::readRectangle(std::istream& input)
{
  point_t left = { 0,0 };
  point_t right = { 0,0 };
  std::string s = "";
  left.x = readNextValue(input);
  left.y = readNextValue(input);
  right.x = readNextValue(input);
  right.y = readNextValue(input);

  return new Rectangle(left, right);;
}

zaitsev::Shape* zaitsev::readComplexquad(std::istream& input)
{
  point_t vertices[4] = {};
  for (size_t i = 0; i < 4; ++i)
  {
    vertices[i].x = readNextValue(input);
    vertices[i].y = readNextValue(input);
  }

  return new Complexquad(vertices);
}

zaitsev::Shape* zaitsev::readParallelogram(std::istream& input)
{
  point_t vertices[3] = {};
  for (size_t i = 0; i < 3; ++i)
  {
    vertices[i].x = readNextValue(input);
    vertices[i].y = readNextValue(input);
  }

  return new Parallelogram(vertices);
}

void zaitsev::readScale(std::istream& input, point_t& center, double& factor)
{
  double x = readNextValue(input);
  double y = readNextValue(input);
  double read_factor = readNextValue(input);

  factor = read_factor;
  center.x = x;
  center.y = y;
}

std::ostream& zaitsev::shapesOutput(std::ostream& output, const Shape* const* shapes, size_t size)
{
  std::ios format_holder(nullptr);
  format_holder.copyfmt(output);
  output.precision(1);
  output.setf(std::ios::fixed);

  double area = 0;
  for (size_t i = 0; i < size; ++i)
  {
    area+=shapes[i]->getArea();
  }

  output << area;

  for (size_t i = 0; i < size; ++i)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    output << " " << frame.pos.x - frame.width / 2 << " " << frame.pos.y - frame.height / 2;
    output << " " << frame.pos.x + frame.width / 2 << " " << frame.pos.y + frame.height / 2;
  }
  output << "\n";
  output.copyfmt(format_holder);
  return output;
}

void zaitsev::freeMemory(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
}

void zaitsev::processShapeInput(std::istream& input, Shape** shapes, size_t& size, Shape* (*handler)(std::istream&))
{
  shapes[size] = handler(input);
  ++size;
}
