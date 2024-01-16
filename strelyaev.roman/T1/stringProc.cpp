#include "stringProc.hpp"
#include <stdexcept>
#include <string>
#include <cstring>
#include "inputShapes.hpp"

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
  if ((string[0] == '\n') || (string[0] == '\0'))
  {
    delete [] string;
    throw std::logic_error("Unable to create string");
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
  point_t start_pos = shape->getFrameRect().pos_;
  shape->move(point);
  shape->scale(k);
  double x = (point.x_ - start_pos.x_) * k;
  double y = (point.y_ - start_pos.y_) * k;
  shape->move(-x, -y);
}