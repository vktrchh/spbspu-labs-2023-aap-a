#include <iostream>
#include <inputString.hpp>
#include "deleteFigures.hpp"
#include "creatingFigures.hpp"
#include "stringManipulations.hpp"
#include "outputResults.hpp"
#include "isoscale.hpp"

int main()
{
  using namespace isaychev;
  size_t capacity = 10;
  Shape * figures[1000] = {};
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  size_t figureCount = 0, figDescMistakeCheck = 0;
  bool eofCheck = false;
  while (figureCount < 1000)
  {
    try
    {
      currDesc = inputString(std::cin, capacity);
      if (checkString(currDesc, scaleStr) == 1 || std::cin.eof())
      {
        if (std::cin.eof())
        {
          eofCheck = true;
        }
        break;
      }
      figures[figureCount++] = createFigure(currDesc);
    }
    catch (const std::bad_alloc &)
    {
      deleteFigures(figures, figureCount);
      delete [] currDesc;
      std::cerr << "can't allocate memory for description of figure or a figure itself\n";
      return 1;
    }
    catch (const std::logic_error &)
    {
      figDescMistakeCheck++;
    }
    if (figures[figureCount - 1] == nullptr)
    {
      figureCount--;
    }
    delete [] currDesc;
  }
  if (figureCount == 0 && checkString(currDesc, scaleStr) == 1)
  {
    delete [] currDesc;
    std::cerr << "nothing to scale\n";
    return 2;
  }
  else if (eofCheck == 1 && checkString(currDesc, scaleStr) == 0)
  {
    deleteFigures(figures, figureCount);
    delete [] currDesc;
    std::cerr << "input was finished with eof symbol; scale wasn't inputed\n";
    return 3;
  }
  else if (countWSpaces(currDesc) >= 1)
  {
    constexpr size_t numOfScalePars = 3;
    double scaleParams[numOfScalePars] = {};
    parseParams(currDesc, numOfScalePars, scaleParams);
    if (scaleParams[2] > 0)
    {
      outputResults(figures, figureCount);
      std::cout << "\n";
    }
    try
    {
      isoscale(figures, figureCount, scaleParams);
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what() << "\n";
      delete [] currDesc;
      deleteFigures(figures, figureCount);
      return 4;
    }
    outputResults(figures, figureCount);
    std::cout << "\n";
  }
  if (figDescMistakeCheck > 0)
  {
    std::cerr << "There were mistakes in figure descriptions\n";
  }
  deleteFigures(figures, figureCount);
  delete [] currDesc;
}
