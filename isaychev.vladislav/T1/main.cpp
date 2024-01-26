#include "deleteFigures.hpp"
#include "creatingFigures.hpp"
#include "stringManipulations.hpp"
#include "inputString.hpp"
#include "outputResults.hpp"
#include "isoscale.hpp"

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  size_t i = 0, figuresCount = 0, figDescMistakeCheck = 0, eofCheck = 0;
  Shape * Figures[1000] = {};
  while (i < 1000)
  {
    try
    {
      currDesc = inputString(std::cin);
      if (checkString(currDesc, scaleStr) == 1 || std::cin.eof())
      {
        if (std::cin.eof())
        {
          eofCheck++;
        }
        break;
      }
      Figures[i++] = createFigure(currDesc);
    }
    catch(const std::bad_alloc &)
    {
      deleteFigures(Figures, figuresCount);
      std::cerr << "can't allocate memory for description of figure or a figure itself\n";
      return 1;
    }
    catch(const std::logic_error &)
    {
      figDescMistakeCheck++;
    }
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
  if (eofCheck == 1 && checkString(currDesc, scaleStr) == 0)
  {
    std::cerr << "input was finished with eof symbol; scale wasn't inputed\n";
    return 2;
  }
  else
  {
    outputResults(Figures, figuresCount);
    try
    {
      isoscale(currDesc, Figures, figuresCount);
    }
    catch (const std::invalid_argument & e)
    {
      if (eofCheck > 0)
      {
        std::cerr << "input was finished with eof symbol; " << e.what() << "\n";
        deleteFigures(Figures, figuresCount);
        return 3;
      }
      std::cerr << e.what() << "\n";
      deleteFigures(Figures, figuresCount);
      return 4;
    }
    outputResults(Figures, figuresCount);
  }
  if (figDescMistakeCheck > 0)
  {
    std::cerr << "There were mistake in figure descriptions\n";
  }
  deleteFigures(Figures, figuresCount);
  delete [] currDesc;
}
