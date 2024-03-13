#include "printShapes.hpp"
#include <iomanip>
#include <ostream>
#include <cstddef>
#include "shape.hpp"

void agarkov::printShapes(std::ostream& out, const agarkov::Shape* const* array, const size_t size)
{
  out << std::fixed << std::setprecision(1);
  double sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum += array[i]->getArea();
  }
  out << sum;

  for (size_t i = 0; i < size; i++)
  {
    out << " ";
    agarkov::rectangle_t frame_rectangle = array[i]->getFrameRectangle();
    double x1 = frame_rectangle.pos_.x_ - frame_rectangle.width_ / 2;
    double y1 = frame_rectangle.pos_.y_ - frame_rectangle.height_ / 2;
    double x2 = frame_rectangle.pos_.x_ + frame_rectangle.width_ / 2;
    double y2 = frame_rectangle.pos_.y_ + frame_rectangle.height_ / 2;
    out << x1 << " " << y1 << " " << x2 << " " << y2;
  }
} 
