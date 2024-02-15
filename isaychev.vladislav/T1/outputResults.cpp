#include "outputResults.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "regular.hpp"

double sumUpAreas(isaychev::Shape *const* figures, size_t figureCount)
{
  double sumOfAreas = 0;
  for (size_t j = 0; j < figureCount; j++)
  {
    sumOfAreas += figures[j]->getArea();
  }
  return sumOfAreas;
}

void isaychev::outputResults(std::ostream & out, Shape *const* figures, size_t figureCount)
{
  out << std::fixed;
  out << std::setprecision(1) << sumUpAreas(figures, figureCount);
  for (size_t j = 0; j < figureCount; j++)
  {
    rectangle_t rect = figures[j]->getFrameRect();
    out << std::setprecision(1) << " " << std::round((rect.pos.x - (rect.width / 2)) * 10) / 10;
    out << std::setprecision(1) << " " << std::round((rect.pos.y - (rect.height / 2)) * 10) / 10;
    out << std::setprecision(1) << " " << std::round((rect.pos.x + (rect.width / 2)) * 10) / 10;
    out << std::setprecision(1) << " " << std::round((rect.pos.y + (rect.height / 2)) * 10) / 10;
  }
}
