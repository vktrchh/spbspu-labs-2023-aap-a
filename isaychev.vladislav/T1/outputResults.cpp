#include "outputResults.hpp"

void isaychev::outputResults(Shape ** Figures, size_t figuresCount)
{
  size_t sumOfAreas = 0;
  for (size_t j = 0; j < figuresCount; j++)
  {
    sumOfAreas += Figures[j]->getArea();
    rectangle_t rect = Figures[j]->getFrameRect();
    std::cout << rect.pos.x_ - (rect.width / 2) << " ";
    std::cout << rect.pos.y_ - (rect.height / 2) << " ";
    std::cout << rect.pos.x_ + (rect.width / 2) << " ";
    std::cout << rect.pos.y_ + (rect.height / 2) << " ";
  }
  std::cout << sumOfAreas << "\n";
}
