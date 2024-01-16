#include "stringProc.hpp"
#include <stdexcept>
#include <string>
#include <cstring>
#include "inputShapes.hpp"
#include <new>

char * strelyaev::inputString(std::istream & in)
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
  if (*string == EOF)
  {
    throw std::logic_error("EOF is met");
  }
  return string;
}

strelyaev::Shape * strelyaev::getShape(const char string[])
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

void strelyaev::isotrScale(Shape * shape, const point_t point, const double k)
{
  point_t start_pos = shape->getFrameRect().pos;
  shape->move(point);
  shape->scale(k);
  double x = (point.x - start_pos.x) * k;
  double y = (point.y - start_pos.y) * k;
  shape->move(-x, -y);
}

void strelyaev::printCoords(Shape * shape)
{
  rectangle_t rect = shape->getFrameRect();
  double left_bottom_x = rect.pos.x - rect.width / 2;
  double left_bottom_y = rect.pos.y - rect.height / 2;
  double right_top_x = rect.pos.x + rect.width / 2;
  double right_top_y = rect.pos.y + rect.height / 2;
  std::cout << shape->getArea() << " " << left_bottom_x << " ";
  std::cout << left_bottom_y << " " << right_top_x << " " << right_top_y << "\n";
}

void strelyaev::outputShapes(std::ostream & out, Shape ** list, size_t current_index)
{
  double sum = 0;
  for (size_t i = 0; i < current_index; i++)
  {
    sum += list[i]->getArea();
  }
  out << sum << " ";

  for (size_t i = 0; i < current_index; i++)
  {
    rectangle_t rect = list[i]->getFrameRect();
    double left_bottom_x = rect.pos.x - rect.width / 2;
    double left_bottom_y = rect.pos.y - rect.height / 2;
    double right_top_x = rect.pos.x + rect.width / 2;
    double right_top_y = rect.pos.y + rect.height / 2;
    out << left_bottom_x << ' ' << left_bottom_y << ' ';
    out << right_top_x << ' ' << right_top_y;
  }
  out << '\n';
}

void strelyaev::scaleShapes(Shape ** list, size_t current_index, const double arguments[3], std::ostream & out)
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
  outputShapes(out, list, current_index);
  for (size_t i = 0; i < current_index; i++)
  {
    isotrScale(list[i], center, arguments[2]);
  }
  outputShapes(out, list, current_index);
}

