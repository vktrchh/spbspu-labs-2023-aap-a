#include <iostream>
#include <inputString.hpp>
#include "creatingFigures.hpp"
#include "stringManipulations.hpp"
#include "outputResults.hpp"
#include "compositeShape.hpp"

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  CompositeShape * cShape = nullptr;
  try
  {
    cShape = new CompositeShape();
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for c. shape or array\n";
    return 1;
  }
  size_t figDescMistakeCheck = 0, capacity = 10, upperBorder =cShape->maxSize();
  bool eofCheck = false;
  while (cShape->size() < upperBorder)
  {
    try
    {
      currDesc = inputString(std::cin, capacity);
      if (checkString(currDesc, scaleStr) || std::cin.eof())
      {
        if (std::cin.eof())
        {
          eofCheck = true;
        }
        break;
      }
      Shape * figure = createFigure(currDesc);
      if (figure != nullptr)
      {
        cShape->pushBack(figure);
      }
   }
    catch (const std::bad_alloc &)
    {
      delete cShape;
      delete [] currDesc;
      std::cerr << "can't allocate memory for description of figure or a figure itself\n";
      return 2;
    }
    catch (const std::logic_error &)
    {
      figDescMistakeCheck++;
    }
    delete [] currDesc;
  }
  if (cShape->size() == 0 && checkString(currDesc, scaleStr) == 1)
  {
    delete cShape;
    delete [] currDesc;
    std::cerr << "nothing to scale\n";
    return 3;
  }
  else if (eofCheck == 1 && checkString(currDesc, scaleStr) == 0)
  {
    delete cShape;
    delete [] currDesc;
    std::cerr << "input was finished with eof symbol; scale wasn't inputed\n";
    return 4;
  }
  else if (countWSpaces(currDesc) >= 1)
  {
    constexpr size_t numOfScalePars = 3;
    double scaleParams[numOfScalePars] = {};
    parseParams(currDesc, numOfScalePars, scaleParams);
    try
    {
      if (scaleParams[2] > 0)
      {
        outputResults(std::cout, cShape);
        std::cout << "\n";
      }
      cShape->scale(scaleParams);
      outputResults(std::cout, cShape);
      std::cout << "\n";
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what() << "\n";
      delete cShape;
      delete [] currDesc;
      return 5;
    }
    catch (const std::out_of_range & e)
    {
      std::cerr << e.what() << "\n";
      delete cShape;
      delete [] currDesc;
      return 6;
    }
  }
  if (figDescMistakeCheck > 0)
  {
    std::cerr << "There were mistakes in figure descriptions\n";
  }
  delete cShape;
  delete [] currDesc;
}
