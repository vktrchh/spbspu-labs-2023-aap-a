#include "Shapes_i_o.h"
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <cstddef>
#include "Shape.h"
#include "Geom_functions.h"

zaitsev::Shape* zaitsev::shapesInput(const std::string& input_str)
{
  Shape* res = nullptr;
  char* input_str_copy = new char[input_str.size() + 1];
  memcpy(input_str_copy, input_str.c_str(), input_str.size() + 1);
  const char* pos = strtok(input_str_copy, " ");
  if (strcmp(pos, "RECTANGLE"))
  {
    Shape* res = readRectangle(input_str_copy);
  }
  else if (strcmp(pos, "COMPLEXQUAD"))
  {
    Shape* res = readRectangle(input_str_copy);


  }
  else if (strcmp(pos, "SCALE"))
  {



  }
  delete[] input_str_copy;

}

double zaitsev::readNextValue()
{
  char* pos = strtok(nullptr, " ");
  char* ptr = nullptr;
  double val = std::strtod(pos, std::addressof(ptr));
  if (val == 0 && ptr == pos)
  {
    throw std::invalid_argument("Read value is not a number");
  }
  return val;
}

zaitsev::Shape* zaitsev::readRectangle(char* param)
{
  strtok(param, " ");

  point_t left = { 0,0 };
  point_t right = { 0,0 };
  left.x = readNextValue();
  left.y = readNextValue();
  right.x = readNextValue();
  right.y = readNextValue();

  return new Rectangle(left, right);
}

zaitsev::Shape* zaitsev::readComplexquad(char* param)
{
  strtok(param, " ");

  point_t vertices[4] = {};
  for (size_t i = 0; i < 4; ++i)
  {
    vertices[i].x = readNextValue();
    vertices[i].y = readNextValue();
  }

  return new Complexquad(vertices);
}

void zaitsev::readScale(char* param, point_t& center, double& factor)
{
  strtok(param, " ");

  double read_factor = readNextValue();
  double x = readNextValue();
  double y = readNextValue();

  factor = read_factor;
  center.x = x;
  center.y = y;
}

std::ostream& zaitsev::shapesOutput(std::ostream& output, Shape** shapes, size_t size)
{
  double area = 0;
  for (size_t i = 0; i < size; ++i)
  {
    area+=shapes[i]->getArea();
  }

  output << area << " ";

  for (size_t i = 0; i < size; ++i)
  {
    rectangle_t frame = shapes[i]->getFrameRect();
    output << frame.pos.x - frame.width / 2 << " " << frame.pos.y - frame.height / 2 << " ";
    output << frame.pos.x + frame.width / 2 << " " << frame.pos.y + frame.height / 2 << " ";
  }
  output << "\n";

  return output;
}