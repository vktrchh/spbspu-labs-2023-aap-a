#include "outputResults.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

double sumUpAreas(isaychev::Shape **const figures, size_t figuresCount)
{
  double sumOfAreas = 0;
  for (size_t j = 0; j < figuresCount; j++)
  {
    sumOfAreas += figures[j]->getArea();
  }
  return sumOfAreas;
}

void isaychev::outputResults(Shape **const figures, size_t figuresCount)
{
  std::cout << std::fixed;
  std::cout << std::setprecision(1) << sumUpAreas(figures, figuresCount);
  for (size_t j = 0; j < figuresCount; j++)
  {
    rectangle_t rect = figures[j]->getFrameRect();
    std::cout << std::setprecision(1) << " " << std::round((rect.pos.x - (rect.width / 2)) * 10) / 10;
    std::cout << std::setprecision(1) << " " << std::round((rect.pos.y - (rect.height / 2)) * 10) / 10;
    std::cout << std::setprecision(1) << " " << std::round((rect.pos.x + (rect.width / 2)) * 10) / 10;
    std::cout << std::setprecision(1) << " " << std::round((rect.pos.y + (rect.height / 2)) * 10) / 10;
  }
}
