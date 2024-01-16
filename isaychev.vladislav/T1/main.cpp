#include "deleteFigures.hpp"
#include "creatingFigures.hpp"
#include "stringManipulations.hpp"
#include "inputString.hpp"
#include "outputResults.hpp"

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  size_t i = 0, figuresCount = 0;
  Shape * Figures[1000] = {};
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
  std::cout << figuresCount << "\n";
  outputResults(Figures, figuresCount);
  Figures[0]->move(2.1, -3.5);
//  Figures[0]->scale(2);
  outputResults(Figures, figuresCount);
  deleteFigures(Figures, figuresCount);
  delete [] currDesc;
}
