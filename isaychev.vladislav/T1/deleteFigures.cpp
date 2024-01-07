#include "deleteFigures.hpp"

void isaychev::deleteFigures(Shape ** arrOfFigures, size_t numOfFigures)
{
  for (size_t i = 0; i < numOfFigures; i++)
  {
    delete arrOfFigures[i];
  }
}
