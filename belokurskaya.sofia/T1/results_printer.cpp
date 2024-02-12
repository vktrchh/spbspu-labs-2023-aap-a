#include <iostream>
#include <iomanip>
#include "results_printer.hpp"

namespace belokurskaya
{
  void printResults(Shape** shapes, int shape_count, double total_area_before_scaling, double total_area_after_scaling)
  {
    std::cout << std::fixed << std::setprecision(1);
    std::cout << total_area_before_scaling;

    for (int i = 0; i < shape_count; ++i)
    {
      std::cout << std::fixed;
      std::cout.precision(1);

      rectangle_t frameRect = shapes[i]->getFrameRect();
      std::cout << " " << frameRect.pos.x - frameRect.width / 2.0 << " " << frameRect.pos.y - frameRect.height / 2.0;
      std::cout << " " << frameRect.pos.x + frameRect.width / 2.0 << " " << frameRect.pos.y + frameRect.height / 2.0;
    }
    std::cout << "\n";

    std::cout << total_area_after_scaling;
    for (int i = 0; i < shape_count; ++i)
    {
      std::cout << std::fixed;
      std::cout.precision(1);
      rectangle_t frameRect = shapes[i]->getFrameRect();
      double scale_lower_left_x = frameRect.pos.x - frameRect.width / 2.0;
      double scale_lower_left_y = frameRect.pos.y - frameRect.height / 2.0;
      double scale_upper_right_x = frameRect.pos.x + frameRect.width / 2.0;
      double scale_upper_right_y = frameRect.pos.y + frameRect.height / 2.0;
      std::cout << " " << scale_lower_left_x << " " << scale_lower_left_y << " " << scale_upper_right_x << " " << scale_upper_right_y;
    }
    std::cout << "\n";
  }
}
