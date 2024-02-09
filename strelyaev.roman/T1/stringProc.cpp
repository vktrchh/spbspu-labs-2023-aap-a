#include "stringProc.hpp"
#include <stdexcept>
#include <string>
#include <cstring>
#include "inputShapes.hpp"

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
  point_t start = shape->getFrameRect().pos;
  shape->move(point);
  point_t moved = shape->getFrameRect().pos;
  double dx = (moved.x - start.x) * k;
  double dy = (moved.y - start.y) * k;
  shape->scale(k);
  shape->move(-dx, -dy);
}

void strelyaev::outputShapes(std::ostream & out, Shape ** list, size_t current_index)
{
  double sum = 0;
  for (size_t i = 0; i < current_index; i++)
  {
    sum += list[i]->getArea();
  }
  out << std::fixed;
  out.precision(1);
  out << sum;

  for (size_t i = 0; i < current_index; i++)
  {
    rectangle_t rect = list[i]->getFrameRect();
    double left_bottom_x = rect.pos.x - rect.width / 2;
    double left_bottom_y = rect.pos.y - rect.height / 2;
    double right_top_x = rect.pos.x + rect.width / 2;
    double right_top_y = rect.pos.y + rect.height / 2;
    out << " " << left_bottom_x << " " << left_bottom_y;
    out << " " << right_top_x << " " << right_top_y;
  }
  out << "\n";
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

