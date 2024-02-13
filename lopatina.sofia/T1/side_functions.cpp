#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include "side_functions.hpp"

bool lopatina::isCentralPoint(point_t point1, point_t point2, point_t point3)
{
  if (((point1.x_ == point2.x_) && (point1.y_ == point3.y_)) || ((point1.x_ == point3.x_) && (point1.y_ == point2.y_)))
  {
    return true;
  }
  return false;
}

lopatina::point_t lopatina::defineSidePointX(point_t point1, point_t point2, point_t point3)
{
  if (point1.x_ == point2.x_)
  {
    return point3;
  }
  else
  {
    return point2;
  }
}

lopatina::point_t lopatina::defineSidePointY(point_t point1, point_t point2, point_t point3)
{
    if (point1.y_ == point2.y_)
  {
    return point3;
  }
  else
  {
    return point2;
  }
}

void lopatina::outputResult(std::ostream & output, Shape ** array, size_t counter)
{
  double sum_area = 0.0;
  for (size_t i = 0; i < counter; ++i)
  {
    sum_area += array[i]->getArea();
  }
  output << std::fixed << std::setprecision(1) << sum_area;
  for (size_t i = 0; i < counter; ++i)
  {
    rectangle_t frame = array[i]->getFrameRect();
    double height = frame.height_;
    double width = frame.width_;
    double pos_x = frame.pos_.x_;
    double pos_y = frame.pos_.y_;
    output << ' ' << round((pos_x - (width / 2.0)) * 10) / 10 << ' ' << round((pos_y - (height / 2.0)) * 10) / 10;
    output << ' ' << round((pos_x + (width / 2.0)) * 10) / 10 << ' ' << round((pos_y + (height / 2.0)) * 10) / 10;
  }
  output << '\n';
}

void lopatina::deleteArray(Shape ** array, size_t counter)
{
  for (size_t i = 0; i < counter; ++i)
  {
    delete array[i];
  }
}
