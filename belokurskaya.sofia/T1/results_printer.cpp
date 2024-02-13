#include <iostream>
#include <iomanip>

#include "results_printer.hpp"

void belokurskaya::printResults(Shape** shapes, int shape_count)
{
  std::cout << std::fixed;
  std::cout.precision(1);

  double area = 0;
  for (int i = 0; i < shape_count; ++i)
  {
    area += shapes[i]->getArea();
  }
  std::cout << area;
  for (int i = 0; i < shape_count; ++i)
  {
    rectangle_t frameRect = shapes[i]->getFrameRect();
    double scale_lower_left_x = frameRect.pos.x - frameRect.width / 2.0;
    double scale_lower_left_y = frameRect.pos.y - frameRect.height / 2.0;
    double scale_upper_right_x = frameRect.pos.x + frameRect.width / 2.0;
    double scale_upper_right_y = frameRect.pos.y + frameRect.height / 2.0;
    std::cout << " " << scale_lower_left_x << " " << scale_lower_left_y << " " << scale_upper_right_x << " " << scale_upper_right_y;
  }
  std::cout << "\n";
}
