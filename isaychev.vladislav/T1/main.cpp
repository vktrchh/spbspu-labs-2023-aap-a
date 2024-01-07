#include <iostream>
#include "deleteFigures.hpp"
#include "createFigure.hpp"
#include "inputString.hpp"

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  size_t capacity = 10, length = 0, i = 0, figuresCount = 0;
  Shape * Figures[1000] = {};
  /*for (size_t k = 0; k < 1000; k++)
  {
    Figures[k] = nullptr;
  }*/
  while (i < 1000)
  {
    try
    {
      currDesc = inputString(std::cin, length, capacity);
    }
    catch(const char * errMessage)
    {
      std::cerr << errMessage << "\n";
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
  for (size_t j = 0; j < figuresCount; j++)
  {
    std::cout << Figures[j]->getArea() << " " << Figures[j]->getFrameRect() << "\n";
    
  }
  deleteFigures(Figures, figuresCount);
  delete [] currDesc;
}
