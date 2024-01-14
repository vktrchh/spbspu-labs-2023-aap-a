#include <iostream>
#include "deleteFigures.hpp"
#include "creatingFigures.hpp"
#include "stringManipulations.hpp"
#include "inputString.hpp"

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  size_t i = 0, figuresCount = 0;
  Shape * Figures[1000] = {};
  double pars[6] = {};
  while (i < 1000)
  {
    try
    {
      currDesc = inputString(std::cin);
    }
    catch(const std::bad_alloc &)
    {
      deleteFigures(Figures, figuresCount);
      std::cerr << "can't allocate memory for description of figure\n";
      return 1;
    }
    if (checkString(currDesc, scaleStr) == 1)
    {
      break;
    }
    Figures[i] = createFigure(currDesc);
    i++;
    if (Figures[i - 1] == nullptr)
    {
      i--;
    }
    else
    {
      figuresCount++;
    }
    delete [] currDesc;
  }
/*  size_t sumOfAreas = 0;
  for (unsigned int j = 0; j < figuresCount; j++)
  {
    sumOfAreas += Figures[j]->getArea();
    rectangle_t rect = Figures[j]->getFrameRect();
    std::cout << rect.pos.x_ - (rect.width / 2) << " ";
    std::cout << rect.pos.y_ - (rect.height / 2) << " ";
    std::cout << rect.pos.x_ + (rect.width / 2) << " ";
    std::cout << rect.pos.y_ + (rect.height / 2) << " ";
  }
  std::cout << sumOfAreas << "\n";
  sumOfAreas = 0;
  Figures[0]->move({2.5, 1.5});
  Figures[0]->scale(2.0);
  for (size_t j = 0; j < figuresCount; j++)
  {
    sumOfAreas += Figures[j]->getArea();
    rectangle_t rect = Figures[j]->getFrameRect();
    std::cout << rect.pos.x_ - (rect.width / 2) << " ";
    std::cout << rect.pos.y_ - (rect.height / 2) << " ";
    std::cout << rect.pos.x_ + (rect.width / 2) << " ";
    std::cout << rect.pos.y_ + (rect.height / 2) << " ";
  }
  std::cout << sumOfAreas << "\n"; */
  deleteFigures(Figures, figuresCount);
  delete [] currDesc;
}
