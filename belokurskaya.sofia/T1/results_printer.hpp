#ifndef RESULTS_PRINTER_HPP
#define RESULTS_PRINTER_HPP

#include "shape.hpp"

namespace belokurskaya {

  struct rectangle_t;

  void printResults(Shape** shapes, int shape_count, double total_area_before_scaling, double total_area_after_scaling);

}

#endif
