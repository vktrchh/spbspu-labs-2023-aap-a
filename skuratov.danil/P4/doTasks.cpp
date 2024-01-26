#include "doTasks.h"
#include "countSaddlePoints.h"
#include "findLongestSeriesRow.h"
#include "findMinSumAlongSecondaryDiagonal.h"
#include "readArray.h"

#include <cstddef>
#include <fstream>
#include <stdexcept>

void skuratov::doTasks(std::ofstream& out, std::ifstream& in, int* array, size_t cols, size_t rows)
{
  try
  {
    skuratov::readArray(in, array, rows, cols);
  }
  catch (const std::exception& e)
  {
    throw;
  }
  int res = skuratov::countSaddlePoints(array, rows, cols);
  out << res << '\n';
  if (!(out << res))
  {
    throw std::exception("Error output file");
  }
  res = skuratov::findMinSumAlongSecondaryDiagonal(array, rows, cols);
  out << res << '\n';
  if (!(out << res))
  {
    throw std::exception("Error output file");
  }
  res = skuratov::findLongestSeriesRow(array, rows, cols);
  out << res << '\n';
  if (!(out << res))
  {
    throw std::exception("Error output file");
  }
}
