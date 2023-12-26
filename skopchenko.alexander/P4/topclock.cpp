#include "topclock.h"

void skopchenko::topClock(int * matrix , size_t dimension , size_t rows)
{
  size_t currentCell = 0;
  size_t currentRow = 0;
  size_t currentCol = 0;
  size_t counter = 1;
  while (currentCol < dimension)
  {
    matrix[currentCell] -= counter;
    counter++;
    currentCell++;
    currentCol++;
  }
  currentCell += 2;
  while (currentRow < dimension)
  {
    matrix[currentCell] -= counter;
    currentCell += rows;
    counter++;
    currentRow++;
  }
}
